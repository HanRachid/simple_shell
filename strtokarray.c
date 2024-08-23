#include <stdlib.h>  /* For malloc, NULL */
#include <string.h>  /* For strtok, strlen, strcpy */

/**
 * strtokarray - Converts a string into an array of strings delimited by the given delimiter.
 * @str: The string to tokenize.
 * @delim: The delimiter used for tokenization.
 * 
 * Return: An array of strings (tokens) or NULL if an error occurs.
 */
char **strtokarray(char *str, const char *delim)
{
    char **arr;
    char *token;
    int i = 0;

    if (str == NULL || delim == NULL)
        return (NULL);

    /* Allocate memory for the array of string pointers */
    arr = malloc(100 * sizeof(char *));
    if (arr == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

		    /* Tokenize the input string */
    token = strtok(str, delim);
    while (token != NULL)
    {
        arr[i] = malloc((strlen(token) + 1) * sizeof(char));
        if (arr[i] == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(arr[i], token);
        token = strtok(NULL, delim);
        i++;
    }

    arr[i] = NULL; /* Null-terminate the array */

	    return (arr);
				}
