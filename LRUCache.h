#ifndef LRUCACHE_H
#define LRUCACHE_H

typedef struct LNode
{
    int key;
    int val;
} LNode;

typedef struct LRUCache
{
    int capacity;
    int size;
    LNode **cacheMap;
} LRUCache;

LNode *createLNode(int key, int val);
LRUCache *createCacheLRU(int capacity);
int getLRU(LRUCache *cache, int key);
void putLRU(LRUCache *cache, int key);
void freeCacheLRU(LRUCache *cache);

#endif