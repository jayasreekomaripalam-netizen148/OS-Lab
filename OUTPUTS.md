# OS Lab - Program Outputs

## 1. Process Chain - Recursive

**File:** `chain_recursive.c`

### Concept
Creates a chain of processes using `fork()` and recursion.

### Expected Structure

```text
P1
 |
P2
 |
P3
 |
P4


---

2. Process Chain - Non-Recursive

File: chain_nonrecursive.c

Concept

Creates a chain of processes using fork() and a loop.

Expected Structure

P1
 |
P2
 |
P3
 |
P4


---

3. Full Binary Process Tree

File: binary_tree.c

Concept

Creates a full binary process tree up to 3 levels.

Process Hierarchy

P1
       /  \
     P2    P3
    / \    / \
   P4 P5  P6 P7

Total processes: 7


---

4. Implementing cp

File: cp.c

System Calls

open()
read()
write()
close()

Purpose

Copies data from a source file to a destination file.


---

5. Implementing mv

File: mv.c

System Call

rename()

Purpose

Moves or renames a file.


---

6. File Error Handling

File: perror_file.c

System Calls / Functions

open()
close()
perror()

Purpose

Attempts to open a non-existing file and displays an appropriate error message.


---

7. IPC Using pipe()

File: pipe_ipc.c

System Calls

fork()
pipe()
read()
write()
close()
wait()

Communication

Parent
   |
   | Message
   ↓
 Child
   |
   | Response
   ↓
Parent

Two pipes are used for two-way communication.


---

Technologies

C Programming

Linux

GCC

Linux System Calls

Process Management

Inter-Process Communication


Author

Jayasree Komaripalam

GitHub: jayasreekomaripalam-netizen148

Save:

```text
CTRL + O
ENTER
CTRL + X

Then commit it:

git add OUTPUTS.md
git commit -m "Add OS Lab program documentation"
git push

That's the next project step—documentation, not testing.
