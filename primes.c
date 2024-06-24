#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "primes.h"

bool is_prime(unsigned long long number)
{
    if (number == 0 || number == 1)
    {
        return false;
    }

    for (unsigned long long i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

void add_primes_to_list(unsigned long long *primes, unsigned long long size)
{
    printf("Starting to add primes to the list\n");
    unsigned long long current_num = 2;
    unsigned long long i = 0;
    while (i < size)
    {
        printf("Currently on number %llu\n", current_num);
        if (is_prime(current_num))
        {
            primes[i] = current_num;
            i++;
        }
        current_num++;
    }
}

bool contains(const unsigned long long *primes, unsigned long long number)
{
    for (size_t i = 0; i < PRIMES_SIZE; i++)
    {
        if (primes[i] == number)
        {
            return true;
        }
    }
    return false;
}