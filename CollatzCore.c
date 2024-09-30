#include <stdio.h>

#define SIZE 1000000

int collatzCache[SIZE];

void cacheInit()
{
    for (int i = 0; i <= SIZE; i++)
    {
        collatzCache[i] = -1;
    }
}

int collatzCore(int n)
{
    int count = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }

        else
        {
            n = 3 * n + 1;
        }
        count++;
    }
    return count;
}

int collatz(int n)
{
    if (collatzCache[n] != -1)
    {
        return collatzCache[n];
    }

    collatzCache[n] = collatzCore(n);
    return collatzCache[n];
}
