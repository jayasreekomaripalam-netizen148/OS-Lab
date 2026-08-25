#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pipe1[2];
    int pipe2[2];

    char message[] = "Hello Child!";
    char response[] = "Hello Parent!";
    char buffer[100];

    if (pipe(pipe1) == -1)
    {
        perror("pipe1 failed");
        exit(1);
    }

    if (pipe(pipe2) == -1)
    {
        perror("pipe2 failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0)
    {
        // Parent process

        close(pipe1[0]);
        close(pipe2[1]);

        // Send message to child
        write(pipe1[1], message, strlen(message) + 1);

        printf("Parent: Message sent to child: %s\n", message);

        // Receive response from child
        read(pipe2[0], buffer, sizeof(buffer));

        printf("Parent: Response received from child: %s\n", buffer);

        close(pipe1[1]);
        close(pipe2[0]);

        wait(NULL);
    }
    else
    {
        // Child process

        close(pipe1[1]);
        close(pipe2[0]);

        // Receive message from parent
        read(pipe1[0], buffer, sizeof(buffer));

        printf("Child: Message received from parent: %s\n", buffer);

        // Send response to parent
        write(pipe2[1], response, strlen(response) + 1);

        printf("Child: Response sent to parent: %s\n", response);

        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}

