#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "primes.h"

void twin_primes(const unsigned long long *primes, unsigned long long i)
{
    if (i < 3)
    {
        printf("The Twin Prime Conjecture is applicable only to primes that is greater than or equal to 3.\n");
        return;
    }

    unsigned long long prime1 = primes[i];
    unsigned long long prime2 = primes[i + 1];

    if (prime2 == prime1 + 2)
    {
        assert(is_prime[prime2]);
        printf("(%llu, %llu)\n", prime1, prime2);
        return;
    }
}