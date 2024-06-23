#ifndef PRIMES_H
#define PRIMES_H

#include <stdbool.h>

typedef struct
{
    int *array;
    size_t length;
} primes_t;

bool is_prime(int number);
void add_primes_to_list(primes_t *primes, int size);
bool contains(const primes_t *primes, int number);

#endif // PRIMES_H