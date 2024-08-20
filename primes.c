#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "primes.h"

bool *is_prime;
unsigned long long *primes;
int prime_count = 0;

void sieve()
{
    is_prime = (bool *)calloc(PRIMES_SIZE + 1, sizeof(bool));
    if (is_prime == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 2; i <= PRIMES_SIZE; i++)
    {
        is_prime[i] = true;
    }
    for (int i = 2; i * i <= PRIMES_SIZE; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= PRIMES_SIZE; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= PRIMES_SIZE; i++)
    {
        if (is_prime[i])
        {
            primes[prime_count++] = i;
        }
    }

    free(is_prime);
}

long long phi(long long n, int k)
{
    if (k == 0)
        return n;
    if (n < primes[k - 1])
        return 1;
    return phi(n, k - 1) - phi(n / primes[k - 1], k - 1);
}

long long pi(long long n)
{
    if (n < MAX_PRIME)
    {
        int count = 0;
        for (int i = 0; i < prime_count && primes[i] <= n; i++)
        {
            count++;
        }
        return count;
    }

    int a = pi(cbrt(n));
    long long result = phi(n, a) + a - 1;

    for (int i = 0; i < a; i++)
    {
        result -= pi(n / primes[i]);
    }

    return result;
}
