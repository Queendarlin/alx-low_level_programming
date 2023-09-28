#include "main.h"

/**
 * recursive_prime - Function to recursively determine if an integer is prime
 * @n: Integer to check whether it is a prime number
 * @tracker: Parameter to track the values checked
 * Return: returns 1 if n is a prime number, else 0
 */

int recursive_prime(int n, int tracker)
{
	if (tracker == 1)
		return (1);
	if (n % tracker == 0 && tracker > 0)
		return (0);
	return (recursive_prime(n, tracker - 1));
}

/**
 * is_prime_number - Function to check if an integer is a prime number
 * @n: Integer to check whether it is a prime number
 * Return: returns 1 if n is a prime number, else 0
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (recursive_prime(n, n - 1));

}
