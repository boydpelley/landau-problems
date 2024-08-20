#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "primes.h"
#include "perfect_squares.h"
#include "goldbachs_conjecture.h"
#include "twin_prime_conjecture.h"
#include "legendres_conjecture.h"

void add_primes()
{
    primes = (unsigned long long *)calloc(PRIMES_SIZE, sizeof(unsigned long long));
    if (primes == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    sieve();
}

void add_squares()
{
    perfect_squares = (unsigned long long *)calloc(SQUARES_SIZE, sizeof(unsigned long long));

    if (perfect_squares == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    add_perfect_squares_to_list(perfect_squares, SQUARES_SIZE);
}

void handle_goldbach()
{
    add_primes();

    for (int i = 2; i < PRIMES_SIZE; i += 2)
    {
        goldbachs(primes, i);
    }

    free(primes);
}

void handle_twin_prime()
{
    add_primes();

    for (int i = 0; i < PRIMES_SIZE - 1; i++)
    {
        twin_primes(primes, i);
    }
}

void handle_legendre()
{
    add_squares();

    for (int i = 0; i < SQUARES_SIZE - 1; i++)
    {
        legendres(perfect_squares, i);
    }
}

int main()
{
    printf("Which landeau problem would you like to see?\n");
    printf("1. Goldbach's Conjecture - Every equal integer greater than 2 is the sum of two primes.\n");
    printf("2. Twin Prime Conjecture - There are infinitely many primes p such that p + 2 is prime.\n");
    printf("3. Legendre's Conjecture - There always exists at least one prime between consecutive perfect squares.\n");

    short conjecture_type = 0;
    while (conjecture_type != 1 || conjecture_type != 2 || conjecture_type != 3)
    {
        scanf("%hd", &conjecture_type);

        if (conjecture_type == 1 || conjecture_type == 2 || conjecture_type == 3)
            break;
        printf("Invalid entry. Try again.\n");
    }

    switch (conjecture_type)
    {
    case 1:
        printf("Starting Goldbach calculations\n");
        handle_goldbach();
        break;
    case 2:
        printf("Starting Twin Prime calculations\n");
        handle_twin_prime();
        break;
    case 3:
        printf("Starting Legendre calculations\n");
        handle_legendre();
        break;
    default:
        break;
    }

    return 0;
}