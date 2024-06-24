#ifndef PRIMES_H
#define PRIMES_H

#include <limits.h>
#include <stdbool.h>

#define PRIMES_SIZE 0xffff

unsigned long long *primes;

bool is_prime(unsigned long long number);
void add_primes_to_list(unsigned long long *primes, unsigned long long size);
bool contains(const unsigned long long *primes, unsigned long long number);

#endif // PRIMES_H