#ifndef FIFOACHE_H
#define FIFOCACHE_H

typedef struct FNode
{
    int key;
    int val;
} FNode;

typedef struct FIFOCache
{
    int capacity;
    int size;
    FNode **cacheMap;
} FIFOCache;

FNode *createFNode(int key, int val);
FIFOCache *createCacheFIFO(int capacity);
void dequeue(FIFOCache *cache);
void enqueue(FIFOCache *cache, int key);
int getFIFO(FIFOCache *cache, int key);
void freeCacheFIFO(FIFOCache *cache);

#endif