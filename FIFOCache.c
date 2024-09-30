#include <stdio.h>
#include <stdlib.h>
#include "CollatzCore.h"

typedef struct FNode
{
    int key;
    int val;
} FNode;

typedef struct FIFOCache
{
    int capacity;
    int size;
    FNode *cacheMap;
} FIFOCache;

FNode *createFNode(int key, int val)
{
    FNode *node = (FNode *)malloc(sizeof(FNode));
    node->key = key;
    node->val = val;
    return node;
}

FIFOCache *createCacheFIFO(int capacity)
{
    FIFOCache *cache = (FIFOCache *)malloc(sizeof(FIFOCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->cacheMap = (FNode *)malloc(capacity * sizeof(FNode));
    return cache;
}

void enqueue(FIFOCache *cache, int key)
{

    // Check if the cache is full, if yes then shift every elements to the left(front) and discard the first element then add to the rear
    if (cache->size >= cache->capacity)
    {
        for (int i = cache->capacity - 1; i > 0; i--)
        {
            cache->cacheMap[i - 1] = cache->cacheMap[i];
        }
        cache->cacheMap[cache->capacity - 1].key = key;
        cache->cacheMap[cache->capacity - 1].val = collatzCore(key);
    }

    // If not then add to the rear of the list
    cache->cacheMap[cache->size + 1].key = key;
    cache->cacheMap[cache->size + 1].val = collatzCore(key);
    cache->size++;
}

int getFIFO(FIFOCache *cache, int key)
{
    for (int i = 0; i < cache->size; i++)
    {
        if (cache->cacheMap[i].key == key)
        {
            return cache->cacheMap[i].val;
        }
    }
    return -1;
}

void freeCacheFIFO(FIFOCache *cache)
{
    free(cache->cacheMap);
    free(cache);
}