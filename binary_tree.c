#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t left, right;

    printf("Level 1 - Root: PID = %d, Parent PID = %d\n",
           getpid(), getppid());

    // Create left child
    left = fork();

    if (left < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (left == 0)
    {
        // Left child of root
        printf("Level 2 - Left: PID = %d, Parent PID = %d\n",
               getpid(), getppid());

        // Create left child's first child
        pid_t l1 = fork();

        if (l1 < 0)
        {
            perror("fork failed");
            exit(1);
        }

        if (l1 == 0)
        {
            printf("Level 3 - Left: PID = %d, Parent PID = %d\n",
                   getpid(), getppid());
        }
        else
        {
            // Create left child's second child
            pid_t l2 = fork();

            if (l2 < 0)
            {
                perror("fork failed");
                exit(1);
            }

            if (l2 == 0)
            {
                printf("Level 3 - Right: PID = %d, Parent PID = %d\n",
                       getpid(), getppid());
            }
            else
            {
                wait(NULL);
                wait(NULL);
            }
        }

        return 0;
    }

    // Root creates right child
    right = fork();

    if (right < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (right == 0)
    {
        // Right child of root
        printf("Level 2 - Right: PID = %d, Parent PID = %d\n",
               getpid(), getppid());

        // Create right child's first child
        pid_t r1 = fork();

        if (r1 < 0)
        {
            perror("fork failed");
            exit(1);
        }

        if (r1 == 0)
        {
            printf("Level 3 - Left: PID = %d, Parent PID = %d\n",
                   getpid(), getppid());
        }
        else
        {
            // Create right child's second child
            pid_t r2 = fork();

            if (r2 < 0)
            {
                perror("fork failed");
                exit(1);
            }

            if (r2 == 0)
            {
                printf("Level 3 - Right: PID = %d, Parent PID = %d\n",
                       getpid(), getppid());
            }
            else
            {
                wait(NULL);
                wait(NULL);
            }
        }

        return 0;
    }

    // Root waits for both children
    wait(NULL);
    wait(NULL);

    return 0;
}

