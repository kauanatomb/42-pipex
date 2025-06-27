# Pipex

**Pipex** is a system-level project from the 42 core curriculum. The goal is to **reproduce the behavior of Unix shell piping**, handling input/output redirections and multiple commands via process management and low-level file descriptors all coded in pure C, without external libraries.

---

## ⚙️ Compilation

```bash
make
./pipex infile "cmd1" "cmd2" outfile
```

This will run the equivalent of:

```bash
< infile cmd1 | cmd2 > outfile
```
Example:

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

## 🧠 Project Goals
- Reproduce the shell’s piping logic using fork, pipe, dup2, and execve.

- Manage input and output file redirections.

- Parse and execute commands with arguments (including flags).

- Handle errors gracefully and ensure memory/resource safety.

## 🧩 Challenges Faced
Matching shell behavior precisely for:

- Quoted arguments

- Environment path resolution

- File permission edge cases

Manual management of:

- File descriptors (open, close, dup2)

- Child processes and their cleanup

- Dynamic memory for argument parsing and paths

- Preventing resource leaks (tested with valgrind and custom leak checks)

- Reimplementing command parsing logic without bash-like parsing tools

## ✅ Key Learnings
- Understanding Unix process model: fork, execve, waitpid

- File descriptor manipulation with dup2, pipe, and redirection

- Parsing shell-like command inputs securely

- Writing error-resilient C code with clean exit paths

- Designing robust CLI applications with modular structure

## 🧪 Testing & Validation
To ensure my implementation matches the shell behavior:

I wrote a test suite that:

- Compares pipex output vs. real shell output using diff

- Tests edge cases (missing files, invalid commands, permission denied)

- Runs under valgrind to catch memory leaks
