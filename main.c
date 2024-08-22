#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prompts the user to enter their name and age,
 *              then prints a greeting message along with their age.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char name[50];
int age;

    /* Prompt the user to enter their name */
printf("Enter your name: ");
fgets(name, sizeof(name), stdin);

    /* Prompt the user to enter their age */
printf("Enter your age: ");
scanf("%d", &age);

    /* Print a greeting message */
printf("Hello, %sYou are %d years old.\n", name, age);

return (0);
}
