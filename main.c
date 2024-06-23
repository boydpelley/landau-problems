#include <stdio.h>
#include <stdlib.h>

#include "primes.h"
#include "goldbachs_conjecture.h"

int main()
{
    size_t size = 50;
    primes_t primes;
    primes.array = (int *)malloc(size * sizeof(int));
    primes.length = size;

    add_primes_to_list(&primes, size);

    int n = 124;
    goldbachs(&primes, n);

    free(primes.array);

    return 0;
}