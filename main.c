#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "primes.h"
#include "goldbachs_conjecture.h"

void handle_goldbach()
{
    primes = (unsigned long long *)calloc(PRIMES_SIZE, sizeof(unsigned long long));

    if (primes == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    add_primes_to_list(primes, PRIMES_SIZE);

    for (int i = 2; i < 0xffff; i += 2)
    {
        goldbachs(primes, i);
    }

    free(primes);
}

int main()
{
    printf("Which landeau problem would you like to see?\n");
    printf("1. Goldbach's Conjecture - Every equal integer greater than 2 is the sum of two primes.\n");
    printf("2. Twin Prime Conjecture - There infinitely many primes p such that p + 2 is prime.\n");
    printf("3. Legendre's Conjecture - There always exists at least one prime between consecutive perfect squares.\n");

    short conjecture_type = 0;
    while (conjecture_type != 1)
    {
        scanf("%hd", &conjecture_type);

        if (conjecture_type == 1)
            break;
        printf("Invalid entry. Try again.\n");
    }

    switch (conjecture_type)
    {
    case 1:
        printf("Starting Goldbach calculations\n");
        handle_goldbach();
        break;

    default:
        break;
    }

    return 0;
}