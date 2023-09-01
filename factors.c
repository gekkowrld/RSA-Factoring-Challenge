#include "challenge.h"

/**
 * main - Open the file and call relevant function
 * @argc: The argument count passed to the program
 * @argv: The actual arguments passed to the program
 *
 * Return: 0
*/

int main(int argc, char *argv[])
{
	FILE *file;
	char *filename = argv[1];

	file = fopen(filename, "r");
	char *line_content = NULL;
	ssize_t line_c = 0;
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (!file)
	{
		fprintf(stderr, "couldn't open %s", filename);
		exit(EXIT_FAILURE);
	}

	while ((line_c = getline(&line_content, &len, file)) != -1)
	{
		mpz_t prime;

		mpz_init(prime);

		mpz_set_str(prime, line_content, 10);
		printf("\n");
		print_prime_numbers(prime);

		mpz_clear(prime);
	}
	putchar('\n');

	fclose(file);

	return (0);
}
