# Operating Systems Lab

This repository contains C programs developed as part of the **Operating Systems Lab**.

The programs demonstrate process creation, process hierarchy, file system calls, error handling, and inter-process communication using Linux system calls.

---

## 📚 Programs

### 1. Process Chain Using fork() - Recursive

**File:** `chain_recursive.c`

Creates a chain of `n` processes using the `fork()` system call and a recursive function.

#### Process Structure

```text
P1
 |
P2
 |
P3
 |
P4
2. Process Chain Using fork() - Non-Recursive
File: chain_nonrecursive.c
Creates a chain of n processes using fork() and a loop instead of recursion.
Process Structure
P1
 |
P2
 |
P3
 |
P4
Concepts Used
fork()
getpid()
getppid()
wait()
for loop
Process hierarchy
3. Full Binary Process Tree up to 3 Levels
File: binary_tree.c
Creates a full binary process tree up to 3 levels using process creation and process hierarchy.
Process Structure
             P1
           /    \
         P2      P3
        /  \    /  \
      P4   P5  P6   P7
Total processes:
7
Concepts Used
fork()
getpid()
getppid()
wait()
Process hierarchy
Parent-child relationship
4. Implement cp Using System Calls
File: cp.c
Implements basic file copying using Linux system calls.
System Call Sequence
Source File
    |
   open()
    |
   read()
    |
  Buffer
    |
  write()
    |
Destination File
    |
  close()
System Calls Used
open()
read()
write()
close()
File Operations
The program reads data from the source file and writes it to the destination file.
5. Implement mv Using System Call
File: mv.c
Implements basic file moving or renaming using the rename() system call.
Operation
old.txt
   |
rename()
   |
   ↓
new.txt
System Call Used
rename()
Error Handling
The program uses perror() if the move/rename operation fails.
6. Open a Non-Existing File Using perror()
File: perror_file.c
Attempts to open a non-existing file using the open() system call.
If the file cannot be opened, an appropriate error message is displayed using perror().
System Call
open("nonexisting.txt", O_RDONLY);
Example Output
Error opening file: No such file or directory
Concepts Used
open()
File descriptor
O_RDONLY
perror()
Error handling
close()
7. Inter-Process Communication Using fork() and pipe()
File: pipe_ipc.c
Demonstrates communication between a parent and child process using pipes.
Two pipes are used for two-way communication.
Communication
Parent
   |
   | Message
   ↓
 Pipe 1
   |
   ↓
Child
   |
   | Response
   ↓
 Pipe 2
   |
   ↓
Parent
Concepts Used
fork()
pipe()
read()
write()
close()
wait()
Inter-Process Communication (IPC)
🛠️ System Calls and Functions Used
System Call / Function
Purpose
fork()
Creates a new process
getpid()
Returns current process ID
getppid()
Returns parent process ID
wait()
Waits for child process
pipe()
Creates IPC communication channel
open()
Opens a file
read()
Reads data from a file/pipe
write()
Writes data to a file/pipe
close()
Closes a file descriptor
rename()
Renames/moves a file
perror()
Displays error information
💻 Requirements
Linux / Unix-like operating system
GCC compiler
C programming knowledge
Basic understanding of Linux system calls
These programs can also be compiled and tested in a suitable Linux environment such as Termux.
▶️ Compilation
General compilation command:
gcc filename.c -o filename
Run:
./filename
Example
gcc chain_recursive.c -o chain_recursive
./chain_recursive
📁 Repository Structure
OS-Lab/
│
├── .gitignore
├── README.md
│
├── chain_recursive.c
├── chain_nonrecursive.c
├── binary_tree.c
├── cp.c
├── mv.c
├── perror_file.c
└── pipe_ipc.c
🎓 Learning Outcomes
Through these programs, I learned about:
Process creation
Parent-child processes
Process IDs
Process hierarchy
Recursive and non-recursive process creation
Linux file system calls
File descriptors
Error handling
Inter-Process Communication
Pipes
Synchronization using wait()
