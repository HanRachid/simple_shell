#include "shell.h"

int exeCommandLine(char *argv[MAX_ARGS])
{
    int fflag;  

    fflag = fork();  

    if (fflag == -1)
    {
        perror("Fork failed");
        return (-1);
    }
    else if (fflag == 0)
    {
        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("Command execution failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(NULL);
        return (0);
    }
    return (2);   
}
