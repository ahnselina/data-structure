#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};

typedef PtrToNode List;

List Read();
void Print(List);

List Merge(List L1, List L2);


int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);

    return 0;
}


List Read()
{
    List p = (List)malloc(sizeof(struct Node));
    p->Next = NULL;
    List tmp = p;

    int n;
    scanf("%d", &n);
    if(n > 0)
    {
        for(int i=0; i<n; i++)
        {
            List new_node = (List)malloc(sizeof(struct Node));
            new_node->Next = NULL;
            scanf("%d", &(new_node->Data));
            tmp->Next = new_node;
            tmp = tmp->Next;
        }
    }

    return p;
}

void Print(List L)
{
    List p = L->Next;
    if(p)
    {
        while(p)
        {
            printf("%d ", p->Data);
            p = p->Next;
        }
    }
    else
    {
        printf("NULL");
    }

    printf("\n");
    return;
}

List Merge(List L1, List L2)
{
    List p1 = L1->Next;
    List p2 = L2->Next;
    List p = (List)malloc(sizeof(struct Node));
    p->Next = NULL;
    List tmp = p;

    while(p1 && p2)
    {
        if(p1->Data < p2->Data)
        {
            tmp->Next = p1;
            tmp = tmp->Next;
            p1 = p1->Next;
        }
        else
        {
            tmp->Next = p2;
            tmp = tmp->Next;
            p2 = p2->Next;
        }
    }

    while(p1)
    {
        tmp->Next = p1;
        tmp = tmp->Next;
        p1 = p1->Next;
    }

    while(p2)
    {
        tmp->Next = p2;
        tmp = tmp->Next;
        p2 = p2->Next;
    }

    tmp->Next = NULL;
    L1->Next = NULL;
    L2->Next =NULL;

    return p;
}
