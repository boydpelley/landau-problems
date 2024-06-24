#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "perfect_squares.h"
#include "primes.h"

bool legendres(const unsigned long long *perfect_squares, unsigned long long first_square)
{
    for (unsigned long long i = perfect_squares[first_square]; i < perfect_squares[first_square + 1]; i++)
    {
        if (is_prime(i))
        {
            printf("Prime number %llu found between perfect squares (%llu, %llu)\n", i, perfect_squares[first_square], perfect_squares[first_square + 1]);
            return true;
        }
    }
    return false;
}