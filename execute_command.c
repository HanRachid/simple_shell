#include "shell.h"


	int fflag = 0;
	fflag = fork();
	if (fflag == -1)
	{
		printf("fealuire");
		return (-1);
	}
	else if (fflag == 0)
	{
		if (execve(argv[0], (char **)argv, NULL) == -1)
		{
			printf("No such file or directory\n");
			return (-1);
		}
	}
	else
	{
		wait(NULL);
		return (0);
	}
	return (2);

