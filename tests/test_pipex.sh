#!/bin/bash

RESET="\033[0m"
GREEN="\033[32m"
RED="\033[31m"

INPUT_DIR="tests/inputs"
OUTPUT_DIR="tests/outputs"
LOG_DIR="tests/logs"

mkdir -p "$INPUT_DIR" "$OUTPUT_DIR" "$LOG_DIR"

create_infile() {
    echo -e "$1" > "$INPUT_DIR/infile"
}

run_test() {
    local name="$1"
    local infile_content="$2"
    local cmd1="$3"
    local cmd2="$4"
    local outfile="${5:-$OUTPUT_DIR/outfile_actual}"
    local valgrind_log="$LOG_DIR/valgrind_${name// /_}.log"

    create_infile "$infile_content"

    # Esperado (shell)
    bash -c "< $INPUT_DIR/infile $cmd1 | $cmd2" > "$OUTPUT_DIR/outfile_expected"
    echo $? > "$OUTPUT_DIR/exit_expected"

    # Pipex (real)
    if [[ "$USE_VALGRIND" == "1" ]]; then
        valgrind --quiet --leak-check=full \
                --track-fds=yes \
                --trace-children=yes \
                --error-exitcode=123 \
                --log-file="$valgrind_log" \
                ./pipex "$INPUT_DIR/infile" "$cmd1" "$cmd2" "$outfile"
        pipex_exit=$?
        [[ "$pipex_exit" -eq 123 ]] && echo -e "${RED}⚠ Valgrind error${RESET}"
        grep -q "descriptor leaked" "$valgrind_log" && echo -e "${RED}⚠ FD leak${RESET}"
    else
        ./pipex "$INPUT_DIR/infile" "$cmd1" "$cmd2" "$outfile"
        pipex_exit=$?
    fi

    echo $pipex_exit > "$OUTPUT_DIR/exit_actual"

    # Comparação
    diff "$OUTPUT_DIR/outfile_expected" "$outfile" > "$LOG_DIR/diff_out.txt"
    diff "$OUTPUT_DIR/exit_expected" "$OUTPUT_DIR/exit_actual" > "$LOG_DIR/diff_exit.txt"

    if [[ -s "$LOG_DIR/diff_out.txt" || -s "$LOG_DIR/diff_exit.txt" || ( "$USE_VALGRIND" == "1" && "$pipex_exit" -eq 123 ) ]]; then
        echo -e "${RED}✘ $name${RESET}"
        [[ -s "$LOG_DIR/diff_out.txt" ]] && echo "  ↳ Output differs:" && cat "$LOG_DIR/diff_out.txt"
        [[ -s "$LOG_DIR/diff_exit.txt" ]] && echo "  ↳ Exit code differs:" && cat "$LOG_DIR/diff_exit.txt"
        if [[ "$USE_VALGRIND" == "1" && "$pipex_exit" -eq 123 ]]; then
            echo "  ↳ Valgrind errors:"
            grep -E "Invalid|definitely|indirectly" "$valgrind_log" | sed 's/^/     /'
        fi
    else
        echo -e "${GREEN}✔ $name${RESET}"
    fi
}

run_zombie_test() {
    local name="$1"
    local infile_content="$2"
    local cmd1="$3"
    local cmd2="$4"
    local outfile="${5:-$OUTPUT_DIR/outfile_actual}"

    create_infile "$infile_content"
    ./pipex "$INPUT_DIR/infile" "$cmd1" "$cmd2" "$outfile" &
    pipex_pid=$!
    check_zombies "$pipex_pid"
    wait $pipex_pid
}

check_zombies() {
    local parent_pid="$1"
    local zombie_count=0

    # Espera um pouco pros processos filhos terminarem
    sleep 0.2

    # Verifica todos os filhos do pipex
    while read -r stat; do
        if [[ "$stat" == Z* ]]; then
            ((zombie_count++))
        fi
    done < <(ps -o stat= --ppid "$parent_pid")

    if [[ "$zombie_count" -gt 0 ]]; then
        echo -e "${RED}⚠ Zombie(s) detected: $zombie_count${RESET}"
    else
        echo -e "${GREEN}✔ No zombies${RESET}"
    fi
}


### Basic tests
run_test "Basic: cat | wc -c" "test content\n" "cat" "wc -c"
run_test "Grep not match" "line one\nline two\n" "grep foo" "wc -l"
run_test "Invalid command" "abc" "nonexistent_cmd" "wc -c"
run_test "Empty infile" "" "cat" "wc -l"
run_test "Pipe: grep match" "foo\nbar\nfoo\n" "grep foo" "wc -l"

### Edge Cases

echo "no access" > "$INPUT_DIR/infile_perm"
chmod 000 "$INPUT_DIR/infile_perm"
run_test "Infile without permission" "" "cat" "wc -l"
chmod 644 "$INPUT_DIR/infile_perm"
run_test "Comando without visible output" "foo\nbar\nbaz\n" "grep -q foo" "wc -l"
run_test "Second command invalid" "abc" "cat" "nonexistent_cmd"
run_test "Command with partial error" "abc\ndef\nghi\n" "cat" "grep --invalid"
run_test "Yes truncated ffor head" "" "yes" "head -n 3"
run_test "Multiple spaces" "abc def\n" "grep abc" "wc   -l"
run_test "Newlines only" "\n\n\n" "cat" "wc -l"
run_test "Large input" "$(head -c 10000 < /dev/zero | tr '\0' 'a')" "cat" "wc -c"
run_test "Unicode content" "😀\n😃\n" "cat" "wc -l"
run_test "Empty command 1" "abc" "" "wc -l"
run_test "Command empty with spaces" "abc" "   " "cat -e"
run_test "Command with space in the begging" "abc" "   ls" "cat -e"
run_test "Cat in directory" "" "cat tests" "wc -l"
run_test "Path absolut wrong" "abc" "/usr/bin/cati" "wc -l"
run_test "Exec wrong" "abc" "./test" "wc -l"
run_test "Empty command 2" "abc" "cat" ""
run_test "Path absolut valid" "foo" "/bin/cat" "/usr/bin/wc -l"
run_test "Command without stdin" "n/a" "echo Hello" "cat"

# Run zumbi tests
run_zombie_test "Test zumbi" "abc" "sleep 0.2" "wc -l"
run_zombie_test "Zombie: invalid cmd1" "abc" "nonexistent" "wc -l"
run_zombie_test "Zombie: invalid cmd2" "abc" "cat" "nonexistent"
run_zombie_test "Zombie: both invalid cmds" "abc" "fail1" "fail2"
run_zombie_test "Zombie: slow cmd2" "abc" "cat" "sleep 0.5"
run_zombie_test "Zombie: slow cmd1" "abc" "sleep 0.5" "cat"
run_zombie_test "Zombie: cmd1 perm denied" "abc" "./no_exec" "cat"
run_zombie_test "Zombie: cmd2 syntax error" "abc" "cat" "grep --bad"
run_zombie_test "Zombie: cmd1 immediate stderr" "abc" "ls invalid_dir" "cat"
run_zombie_test "Zombie: cmd2 finishes fast" "abc" "yes" "head -n 1"

## For manual tests
# echo -e "one two\nthree foo" > infile
# cat infile | grep foo | wc -l > expected
# echo $? > exit_expected

# ./pipex infile "grep foo" "wc -l" outfile
# echo $? > exit_actual

# diff expected outfile
# diff exit_expected exit_actual

# Test with Valgrind
# valgrind --leak-check=full --trace-children=yes ./pipex infile "cmd1" "cmd2" outfile
