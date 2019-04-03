#include <stdio.h>
#include <stdlib.h>


int gCapacity = 0;
int gPosition = 0;

typedef struct tag {
    int key;
    int value;
    struct tag *next;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    gCapacity = capacity;
    LRUCache* pHead = (LRUCache *)malloc(sizeof(LRUCache));
    if(NULL == pHead)
    {
        printf("%s excute failed.\n", __FUNCTION__);
        return NULL;
    }

    pHead->next = NULL;
    return pHead;
}

void moveNodeToFirst(LRUCache* obj, int key)
{
    LRUCache* pre = NULL;
    LRUCache* cur = NULL;
    LRUCache* p = obj;
    while(p->next)
    {
        if(key == p->next->key)
        {
            pre = p;
            cur = p->next;
            break;
        }
        p = p->next;
    }

    pre->next = cur->next;
    cur->next = obj->next;
    obj->next = cur;
}


int lRUCacheGet(LRUCache* obj, int key) {
    if(NULL == obj)
    {
        return -1;
    }

    LRUCache* p = obj->next;
    while(p)
    {
        if(key == p->key)
        {
            moveNodeToFirst(obj, key);
            return p->value;
        }
        p = p->next;
    }

    return -1;
}

void updateNodeValue(LRUCache* obj, int key, int value)
{
    LRUCache* p = obj->next;
    while(p)
    {
        if(key == p->key)
        {
             p->value = value;
             break;
        }
        p = p->next;
    }

}


void insertNodeToFirst(LRUCache* obj, int key, int value)
{
    LRUCache* newNode = (LRUCache*)malloc(sizeof(LRUCache));
    if(NULL == newNode)
    {
        printf("%s malloc failed.\n", __FUNCTION__);
        return;
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = obj->next;
    obj->next = newNode;
}

void deleteLastNode(LRUCache** obj)
{
    LRUCache* p = *obj;
    while(p->next && p->next->next)
    {
        p = p->next;
    }

    LRUCache* tmp = p->next;
    p->next = NULL;
    free(tmp);
}


void lRUCachePut(LRUCache* obj, int key, int value) {
    if(-1 != lRUCacheGet(obj, key))
    {
        updateNodeValue(obj, key, value);
        moveNodeToFirst(obj, key);
    }
    else if(gPosition != gCapacity)
    {
        insertNodeToFirst(obj, key, value);
        gPosition++;
    }
    else
    {
        deleteLastNode(&obj);
        insertNodeToFirst(obj, key, value);
    }
}

void lRUCacheFree(LRUCache* obj) {
    LRUCache* p = obj;
    while(p->next)
    {
       LRUCache* next = p->next;
       p->next = next->next;
       free(next);
    }
    free(obj);
    obj = NULL;
    gCapacity = 0;
    gPosition = 0;
}


void lRUPrint(LRUCache* obj)
{
   LRUCache* p = obj->next;
   while(p)
   {
       printf("(%d %d)->", p->key, p->value);
       p = p->next;
   }
   printf("\n");
}


int main()
{
    printf("=====testcase1:\n");
    LRUCache* p = lRUCacheCreate(2);
    lRUCachePut(p, 1, 1);
    lRUCachePut(p, 2, 2);
    int res = lRUCacheGet(p, 1);
    printf("get 1 res:%d\n", res);
    lRUCachePut(p, 3, 3);
    res = lRUCacheGet(p, 2);
    printf("get 2 res:%d\n", res);
    lRUCachePut(p, 4, 4);
    res = lRUCacheGet(p, 1);
    printf("get 1 res:%d\n", res);
    res = lRUCacheGet(p, 3);
    printf("get 3 res:%d\n", res);
    res = lRUCacheGet(p, 4);
    printf("get 4 res:%d\n", res);
    lRUCacheFree(p);
    printf("=====testcase2:\n");
    p = lRUCacheCreate(1);
    lRUCachePut(p, 2, 1);
    res = lRUCacheGet(p, 2);
    printf("res:%d\n", res);
    lRUPrint(p);
    lRUCachePut(p, 3, 2);
    lRUPrint(p);
    res = lRUCacheGet(p, 2);
    printf("res:%d\n", res);
    lRUPrint(p);
    res = lRUCacheGet(p, 3);
    printf("res:%d\n", res);
    lRUPrint(p);
    lRUCacheFree(p);

    return 0;
}
