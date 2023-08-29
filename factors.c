#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <gmp.h>
#include <unistd.h>

void print_prime_numbers(mpz_t number);

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

	fclose(file);

	return (0);
}

/**
 * print_prime_numbers - Print the prime factors (numbers)
 * @number: The number to be factored by the program
 *
*/

void print_prime_numbers(mpz_t number)
{
	mpz_t i, quotient;

	mpz_inits(i, quotient, NULL);

	if (mpz_cmp_ui(number, 1) == 0 || mpz_cmp_ui(number, 2) == 0)
	{
		gmp_printf("%Zd=%Zd*1", number, number);
		mpz_clears(i, quotient, NULL);
		return;
	}

	mpz_set_ui(i, 2);
	int divisor_found = 0;

	while (mpz_cmp(i, number) <= 0)
	{
		mpz_mod(quotient, number, i);
		if (mpz_cmp_ui(quotient, 0) == 0)
		{
			mpz_t result;

			mpz_init(result);

			mpz_divexact(result, number, i);
			gmp_printf("%Zd=%Zd*%Zd", number, result, i);

			mpz_clear(result);

			divisor_found = 1;
			break;
		}
		mpz_add_ui(i, i, 1);
	}

	if (!divisor_found)
	{
		gmp_printf("%Zd=%Zd*1", number, number);
	}

	mpz_clears(i, quotient, NULL);
}

