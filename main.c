#include "shell.h"

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    char *argv[MAX_ARGS];

    while (1)
    {
        printf("shell$ "); // Display prompt
        if (getline(&buffer, &bufsize, stdin) == -1)
        {
            perror("getline error");
            free(buffer);
            exit(EXIT_FAILURE);
        }

        // Parse input into argv array
        int i = 0;
        char *token = strtok(buffer, " \n");
        while (token != NULL && i < MAX_ARGS - 1)
        {
            argv[i++] = token;
            token = strtok(NULL, " \n");
        }
        argv[i] = NULL;

        if (argv[0] == NULL) // Check if no command was entered
            continue;

        if (_strcmp(argv[0], "exit") == 0) // Exit command
        {
            free(buffer);
            exit(0);
        }

        if (exeCommandLine(argv) == -1)
        {
            printf("Command execution failed\n");
        }
    }
    free(buffer);
    return 0;
}
