#include <stdio.h>
#include <stdlib.h>
#include "CollatzCore.h"

typedef struct LNode
{
    int key;
    int val;
} LNode;

typedef struct LRUCache
{
    int capacity;
    int size;
    LNode *cacheMap;
} LRUCache;

LNode *createLNode(int key, int val)
{
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->key = key;
    node->val = val;
    return node;
}

LRUCache *createCacheLRU(int capacity)
{
    LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->cacheMap = (LNode *)malloc(capacity * sizeof(LNode));
    return cache;
}

int getLRU(LRUCache *cache, int key)
{
    for (int i = 0; i < cache->size; i++)
    {
        if (cache->cacheMap[i].key == key) // Iterate through the hash
        {
            LNode entry = cache->cacheMap[i];
            for (int j = i; j > 0; j--)
            {
                cache->cacheMap[j] = cache->cacheMap[j - 1];
            }

            // Set the accessed node to be the head(MRU)
            cache->cacheMap[0] = entry;
            return entry.val;
        }
    }
    return -1;
}

void putLRU(LRUCache *cache, int key)
{
    // Check if the cache is full, if yes then shift every elements to the right(tail) and discard the last element(LRU) then add to the head
    if (cache->size >= cache->capacity)
    {
        for (int i = cache->capacity - 1; i > 0; i--)
        {
            cache->cacheMap[i] = cache->cacheMap[i - 1];
        }
        cache->cacheMap[0].key = key;
        cache->cacheMap[0].val = collatzCore(key);
        cache->size++;
    }

    // If not then shift every elements to the right(tail) and add to the head of the list
    else
    {
        for (int i = cache->size; i > 0; i--)
        {
            cache->cacheMap[i] = cache->cacheMap[i - 1];
        }
        cache->cacheMap[0].key = key;
        cache->cacheMap[0].val = collatzCore(key);
        cache->size++;
    }
}

void freeCacheLRU(LRUCache *cache)
{
    free(cache->cacheMap);
    free(cache);
}