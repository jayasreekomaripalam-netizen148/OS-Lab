#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int n;
    pid_t pid;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Root Process: PID = %d, Parent PID = %d\n",
           getpid(), getppid());

    for (int i = 1; i < n; i++)
    {
        pid = fork();

        if (pid < 0)
        {
            perror("fork failed");
            exit(1);
        }

        if (pid == 0)
        {
            printf("Child %d: PID = %d, Parent PID = %d\n",
                   i, getpid(), getppid());
        }
        else
        {
            wait(NULL);
            break;
        }
    }

    return 0;
}

