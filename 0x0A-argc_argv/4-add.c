#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Adds positive numbers.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments.
 * Return: 0 if successful, 1 if an error occurred.
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int i, j, num;

	for (i = 1; i < argc; i++)
	{
		num = 0;

		/* Check if the argument contains non-digit characters */
		for (j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}

		/* Convert the argument to an integer and add it to the sum */
		num = atoi(argv[i]);
		if (num <= 0)
		{
			continue; /* Skip negative or zero values */
		}
		sum += num;
	}

	/* Print the sum or 0 if there were no positive arguments */
	printf("%d\n", sum);

	return (0);
}

