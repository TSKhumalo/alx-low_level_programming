#include "hash_tables.h"

/**
 * hash_djb2 - function that uses the djb2 algorithm
 * @str: string
 * Description: 1. djb2
 * This algorithm (k=33) was first reported by Dan Bernstein
 * many years ago in comp.lang.c.  Another version of this algorithm
 * (now favored by bernstein) uses xor: hash(i) = hash(i - 1) * 33 ^ str[i].
 * The magic of number 33 (why it works better than many other constants,
 * prime or not) has never been adequately explained.
 * Return: see below
 * upon success, hash
 * upon fail, nothing
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
