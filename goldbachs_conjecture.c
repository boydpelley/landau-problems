#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "primes.h"
#include "goldbachs_conjecture.h"

void goldbachs(const unsigned long long *primes, unsigned long long n)
{
    if (n < 4 || n % 2 != 0)
    {
        printf("Goldbach's conjecture is applicable only to even numbers greater than 2.\n");
        return;
    }

    for (unsigned long long i = 0; i < PRIMES_SIZE; i++)
    {
        unsigned long long prime1 = primes[i];
        if (prime1 >= n)
            break; // No need to check primes greater than or equal to n

        unsigned long long prime2 = n - prime1;
        if (contains(primes, prime2))
        {
            assert(prime1 + prime2 == n);
            printf("%llu = %llu + %llu\n", n, prime1, prime2);
            return;
        }
    }

    printf("Goldbach's Conjecture could not be verified for %llu.\n", n);
}
