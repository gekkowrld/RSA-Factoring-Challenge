#include "challenge.h"

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
