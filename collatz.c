#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CollatzCore.h"
#include "LRUCache.h"
#include "FIFOCache.h"

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);
    char *cachePolicy = argv[4];
    int cacheSize = atoi(argv[5]);
    int hits = 0;

    if (strcmp(cachePolicy, "LRU") == 0)
    {
        LRUCache *cache = createCacheLRU(cacheSize);
        for (int i = 0; i < n; i++)
        {
            int randomNumber = rand() % (max - min + 1) + min;
            int steps = getLRU(cache, randomNumber);
            printf("The random number is %d and it takes %d steps until it results in 1 \n", randomNumber, steps);

            if (steps == -1)
            {
                putLRU(cache, randomNumber);
            }

            else
            {
                hits++;
            }
        }
        freeCacheLRU(cache);
        double hitRate = (double)hits / n * 100;
        printf("Cache hit rate: %.2f%%\n", hitRate);
    }

    else if (strcmp(cachePolicy, "FIFO") == 0)
    {
        FIFOCache *cache = createCacheFIFO(cacheSize);
        for (int i = 0; i < n; i++)
        {
            int randomNumber = rand() % (max - min + 1) + min;
            int steps = getFIFO(cache, randomNumber);

            if (steps == -1)
            {
                enqueue(cache, randomNumber);
            }
            else
            {
                hits++;
            }
        }
        freeCacheFIFO(cache);
        double hitRate = (double)hits / n * 100;
        printf("Cache hit rate: %.2f%%\n", hitRate);
    }

    else if (strcmp(cachePolicy, "none") == 0)
    {
        cacheInit();
        for (int i = 0; i < n; i++)
        {
            int randomNumber = rand() % (max - min + 1) + min;
            int steps = collatz(randomNumber);
        }
    }

    return 0;
}