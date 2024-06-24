#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "primes.h"

void add_perfect_squares_to_list(unsigned long long *squares, unsigned long long size)
{
    printf("Adding perfect squares to the list.\n");
    for (unsigned long long i = 1; i < size; i++)
    {
        unsigned long long square = i * i;
        printf("Adding square of %llu, %llu\n", i, square);
        squares[i] = square;
    }
}