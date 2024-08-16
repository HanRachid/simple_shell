#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PROMPT "simple_shell$ "

/* Declare environ */
extern char **environ;

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t nread;
    char *args[2]; /* We only need space for one command and a NULL terminator. */
    pid_t pid;
    int status;

    while (1)
    {
        /* Display the prompt */
        printf(PROMPT);
        
        /* Read the command */
        nread = getline(&buffer, &bufsize, stdin);
        if (nread == -1)
        {
            if (feof(stdin))  /* Handle Ctrl+D (EOF) */
            {
                printf("\n");
                break;
            }
            else
            {
                perror("getline");
                continue;
            }
        }

        /* Remove newline character from the input */
        buffer[strcspn(buffer, "\n")] = 0;

        /* Check if the user entered nothing (just pressed Enter) */
        if (buffer[0] == '\0')
            continue;

        /* Prepare arguments for execve */
        args[0] = buffer;
        args[1] = NULL;

        /* Fork a child process */
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            continue;
        }

        if (pid == 0) /* Child process */
        {
            /* Execute the command */
            if (execve(args[0], args, environ) == -1)
            {
                perror(args[0]);
                exit(EXIT_FAILURE);
            }
        }
        else /* Parent process */
        {
            /* Wait for the child process to complete */
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    free(buffer); /* Free the buffer allocated by getline */
    return 0;
}
