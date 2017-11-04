#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
typedef struct NodeList
{
    int element;
    struct NodeList *next;
}Node;


/* 初始化带头结点的单链表 */

void InitList(Node **pNode)
{
    *pNode = (Node *)malloc(sizeof(Node));
    if(NULL == *pNode)
    {
        printf("%s executed, malloc failed, failed to init List.\n", __FUNCTION__);
        return;
    }

    (*pNode)->next = NULL;
    printf("%s executed succesfully, init List finished.\n", __FUNCTION__);
    return;
}


void CreateList(Node *pNode)
{
    Node *p = (Node *)malloc(sizeof(Node));//notice if malloc is success
    p->next = NULL;
    Node *tmp = p;

    int n;
    scanf("%d", &n);
    if(n > 0)
    {
        for(int i=0; i<n; i++)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->next = NULL;
            scanf("%d", &(newNode->element));
            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
    pNode = p;
    return;
}

void PrintList(Node *pNode)
{
    Node *p = pNode->next;
    while(p)
    {
        printf("%d ", p->element);
        p = p->next;
    }

    printf("\n Function %s executed, print list successfully.\n", __FUNCTION__);
    return;
}


void ClearList(Node *pNode)
{
    Node *p = pNode->next;
    while(p)
    {
        pNode->next = p->next;
        free(p);
        p = pNode->next;
    }

    printf("Function %s executed, clear list successfully.\n", __FUNCTION__);
    return;
}

int SizeList(Node *pNode)
{
    int i = 0;
    Node *p = pNode->next;
    while(p)
    {
        i++;
        p = p->next;
    }

    printf("Function %s executed, list size is %d.\n", __FUNCTION__, i);
    return i;
}

//返回单链表中第pos个结点中的元素，若返回-1，表示没有找到
int FindElement(Node *pNode, int pos)
{
    int i = 1;
    Node *p = pNode->next;
    while(p)
    {
        if(pos == i)
        {
            printf("Funtion %s executed，the value in pos=%d is %d\n", __FUNCTION__, pos, p->element);
            return p->element;
        }

        i++;
        p = p->next;
    }

    printf("Funtion %s executed，the value in pos=%d is not found.\n", __FUNCTION__, pos);
    return -1;
}


Node *ModifyElem(Node *pNode, int pos, int x)
{
    int i = 1;
    Node *p = pNode->next;
    while(p)
    {
        if(pos == i)
        {
            p->element = x;
            printf("Function %s executed, now the value pos=%d is %d.\n", __FUNCTION__, pos, x);
            return pNode;
        }
        i++;
        p = p->next;
    }

    printf("Function %s executed failed, maybe the list is NULL or the pos is invalid.\n", __FUNCTION__);

    return pNode;
}

//表头插入一个节点
Node *InsertHead(Node *pNode, int x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->element = x;
    p->next = pNode->next;
    pNode->next = p;

    printf("Function %s executed, insert %d in head successfully.\n", __FUNCTION__, x);
    return pNode;
}

//表尾插入一个节点
Node *InsertTail(Node *pNode, int x)
{
    Node *p = pNode->next;
    Node *pInsert = (Node *)malloc(sizeof(Node));
    pInsert->element = x;
    pInsert->next = NULL;

    while(p)
    {
        p = p->next;
    }

    p->next = pInsert;
    printf("Function %s executed, insert %d in tail successfully.\n", __FUNCTION__, x);

    return pNode;
}


int main(void)
{
    Node *pList;
    InitList(&pList);

    CreateList(pList);

    PrintList(pList);

    SizeList(pList);

    FindElement(pList, 3);

    ModifyElem(pList, 2, 11);

    PrintList(pList);

    InsertHead(pList, 2333);
    PrintList(pList);
    SizeList(pList);

    InsertTail(pList, 8888);
    PrintList(pList);
    SizeList(pList);

    ClearList(pList);
    PrintList(pList);

    return 0;
}

