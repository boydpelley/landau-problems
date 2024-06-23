#include <stdio.h>
#include <stdlib.h>

#include "primes.h"
#include "goldbachs_conjecture.h"

void goldbachs(const primes_t *primes, int n)
{
    if (n < 4 || n % 2 != 0)
    {
        printf("Goldbach's conjecture is applicable only to even numbers greater than 2.\n");
        return;
    }

    for (size_t i = 0; i < primes->length; ++i)
    {
        int prime1 = primes->array[i];
        if (prime1 >= n)
            break; // No need to check primes greater than or equal to n

        int prime2 = n - prime1;
        if (contains(primes, prime2))
        {
            printf("%d = %d + %d\n", n, prime1, prime2);
            return;
        }
    }

    printf("Goldbach's conjecture could not be verified for %d.\n", n);
}
