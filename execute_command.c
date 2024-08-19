#include "shell.h"
int exeCommandLine(char *argv[MAX_ARGS])
{
	int fflag = 0;
	/* ------------------fork to child execve-------------------------*/
	fflag = fork();
	if (fflag == -1)
	{
i		/*printf("fealuire");*/
		return (-1);
	}
	else if (fflag == 0)
	{
		/* --------------------------child execve--------------------*/
		if (execve(argv[0], (char **)argv, NULL) == -1)
		{
			/*printf("No such file or directory\n");*/
			return (-1);
		}
	}
	else
	{
		/* --------------------------wait child execve--------------------*/
		wait(NULL);
		return (0);
	}
	return (2);
}
