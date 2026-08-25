#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char source[100];
    char destination[100];

    printf("Enter source file: ");
    scanf("%99s", source);

    printf("Enter destination file: ");
    scanf("%99s", destination);

    if (rename(source, destination) == -1)
    {
        perror("Error moving file");
        return 1;
    }

    printf("File moved successfully.\n");

    return 0;
}

