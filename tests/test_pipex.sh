#!/bin/bash

RESET="\033[0m"
GREEN="\033[32m"
RED="\033[31m"

INPUT_DIR="tests/inputs"
OUTPUT_DIR="tests/outputs"
LOG_DIR="tests/logs"

mkdir -p "$INPUT_DIR" "$OUTPUT_DIR" "$LOG_DIR"

run_test() {
    local name="$1"
    local infile_content="$2"
    local cmd1="$3"
    local cmd2="$4"
    local valgrind_log="$LOG_DIR/valgrind_${name// /_}.log"

    echo -e "$infile_content" > "$INPUT_DIR/infile"
    
    # Shell
    bash -c "< $INPUT_DIR/infile $cmd1 | $cmd2" > "$OUTPUT_DIR/outfile_expected"
    echo $? > "$OUTPUT_DIR/exit_expected"

    if [[ "$USE_VALGRIND" == "1" ]]; then
        valgrind --quiet --leak-check=full \
                 --error-exitcode=123 \
                 --log-file="$valgrind_log" \
                 ./pipex "$INPUT_DIR/infile" "$cmd1" "$cmd2" "$OUTPUT_DIR/outfile_actual"
        pipex_exit=$?
    else
        ./pipex "$INPUT_DIR/infile" "$cmd1" "$cmd2" "$OUTPUT_DIR/outfile_actual"
        pipex_exit=$?
    fi

    echo $pipex_exit > "$OUTPUT_DIR/exit_actual"

    # Diff
    diff "$OUTPUT_DIR/outfile_expected" "$OUTPUT_DIR/outfile_actual" > "$LOG_DIR/diff_out.txt"
    diff "$OUTPUT_DIR/exit_expected" "$OUTPUT_DIR/exit_actual" > "$LOG_DIR/diff_exit.txt"

    if [[ -s "$LOG_DIR/diff_out.txt" || -s "$LOG_DIR/diff_exit.txt" || ( "$USE_VALGRIND" == "1" && "$pipex_exit" -eq 123 ) ]]; then
        echo -e "${RED}✘ $name${RESET}"

        [[ -s "$LOG_DIR/diff_out.txt" ]] && echo -e "  ↳ Diff output:" && cat "$LOG_DIR/diff_out.txt"
        [[ -s "$LOG_DIR/diff_exit.txt" ]] && echo -e "  ↳ Diff exit code:" && cat "$LOG_DIR/diff_exit.txt"
        if [[ "$USE_VALGRIND" == "1" && "$pipex_exit" -eq 123 ]]; then
            echo -e "  ↳ Valgrind errors:"
            grep -E "Invalid|definitely|indirectly" "$valgrind_log" | sed 's/^/     /'
        fi
    else
        echo -e "${GREEN}✔ $name${RESET}"
    fi
}


### Basic tests
run_test "Basic: cat | wc -c" "test content\n" "cat" "wc -c"
run_test "Grep not match" "line one\nline two\n" "grep foo" "wc -l"
run_test "Invalid command" "abc" "nonexistent_cmd" "wc -c"
run_test "Empty infile" "" "cat" "wc -l"
run_test "Pipe: grep match" "foo\nbar\nfoo\n" "grep foo" "wc -l"

### Edge Cases

chmod 000 tests_pipex/infile_perm
run_test "Infile without permition" "$(echo 'without access')" "cat" "wc -l"
chmod 644 tests_pipex/infile_perm
run_test "Comando without visible output" "foo\nbar\nbaz\n" "grep -q foo" "wc -l"
run_test "Second command invalid" "abc" "cat" "nonexistent_cmd"
run_test "Command with partial error" "abc\ndef\nghi\n" "cat" "grep --invalid"
run_test "Yes truncated ffor head" "" "yes" "head -n 3"
run_test "Multiple spaces" "abc def\n" "grep abc" "wc   -l"
run_test "Newlines only" "\n\n\n" "cat" "wc -l"
run_test "Large input" "$(head -c 10000 < /dev/zero | tr '\0' 'a')" "cat" "wc -c"
run_test "Unicode content" "😀\n😃\n" "cat" "wc -l"
run_test "Empty command 1" "abc" "" "wc -l"
run_test "Empty command 2" "abc" "cat" ""
run_test "Command empty with spaces" "abc" "   " "cat -e"
run_test "Command with space in the begging" "abc" "   ls" "cat -e"
# Should fail
run_test "Cat in directory" "" "cat tests_pipex/" "wc -l"

## For manual tests
# echo -e "one two\nthree foo" > infile
# cat infile | grep foo | wc -l > expected
# echo $? > exit_expected

# ./pipex infile "grep foo" "wc -l" outfile
# echo $? > exit_actual

# diff expected outfile
# diff exit_expected exit_actual
