#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "primes.h"

bool is_prime(int number)
{
    if (number == 0 || number == 1)
    {
        return false;
    }

    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

void add_primes_to_list(primes_t *primes, int size)
{
    int current_num = 0;
    size_t i = 0;
    while (i < size)
    {
        if (is_prime(current_num))
        {
            primes->array[i] = current_num;
            i++;
        }
        current_num++;
    }
}

bool contains(const primes_t *primes, int number)
{
    for (size_t i = 0; i < primes->length; i++)
    {
        if (primes->array[i] == number)
        {
            return true;
        }
    }
    return false;
}