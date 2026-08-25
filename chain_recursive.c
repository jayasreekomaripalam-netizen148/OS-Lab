#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void create_chain(int n)
{
    if (n <= 1)
        return;

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Child Process: PID = %d, Parent PID = %d\n",
               getpid(), getppid());

        create_chain(n - 1);
    }
    else
    {
        wait(NULL);
    }
}

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Root Process: PID = %d, Parent PID = %d\n",
           getpid(), getppid());

    create_chain(n);

    return 0;
}

