#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
 * print_environment - Prints the current environment variables.
 */
void print_environment(void)
{
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}

/**
 * main - A simple UNIX command line interpreter
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *args[2];
    pid_t pid;
    int status;

    while (1)
    {
        /* Display prompt */
        printf("#cisfun$ ");

        /* Read input from the user */
        nread = getline(&line, &len, stdin);
        if (nread == -1) /* Handle EOF (Ctrl+D) */
        {
            printf("\n");
            break;
        }

        /* Remove newline character from the input */
        line[strcspn(line, "\n")] = 0;

        /* Prepare arguments for execve */
        args[0] = line; /* Command to execute */
        args[1] = NULL; /* No arguments */

        /* Fork a child process */
        pid = fork();
        if (pid == 0) /* Child process */
        {
            /* Execute command */
            if (execve(args[0], args, environ) == -1)
            {
                perror("./hsh");
            }
            exit(EXIT_FAILURE);
        }
        else if (pid > 0) /* Parent process */
        {
            wait(&status);

            /* After executing the command, print environment variables */
            print_environment();
        }
        else
        {
            perror("fork");
        }
    }

    free(line);
    return (0);
}
