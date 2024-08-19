#include "shell.h"

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t line_size;
    char *argv[MAX_ARGS];
    int status = 0;
    
    while (1)
    {
        /* Display prompt in interactive mode */
        if (isatty(STDIN_FILENO))
            write(1, "($) ", 4);

        /* Get the command line from the user */
        line_size = getline(&buffer, &bufsize, stdin);
        if (line_size == -1)
        {
            free(buffer);
            exit(EXIT_FAILURE);
        }

        /* Remove newline character from the input */
        if (buffer[line_size - 1] == '\n')
            buffer[line_size - 1] = '\0';

        /* Split the command line into arguments */
        cutCommandLine(buffer, argv);

        /* If the command is empty, continue to the next loop */
        if (argv[0] == NULL)
            continue;

        /* Check for built-in commands (e.g., "exit") */
        if (_strcmp(argv[0], "exit") == 0)
        {
            free(buffer);
            exit(EXIT_SUCCESS);
        }

        /* Execute the command */
        status = exeCommandLine(argv);
        if (status == -1)
        {
            perror("Error");
        }
    }
    free(buffer);
    return (0);
}
