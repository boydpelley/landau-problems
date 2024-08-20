#ifndef PRIMES_H
#define PRIMES_H

#include <limits.h>
#include <stdbool.h>

#define MAX_N 1000000000
#define MAX_PRIME 1000000
#define PRIMES_SIZE 0xffff

bool *is_prime;
unsigned long long *primes;

void sieve();
long long phi(long long n, int k);
long long pi(long long n);

#endif // PRIMES_H