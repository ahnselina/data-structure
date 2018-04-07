#include <stdio.h>


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;

    return;
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        //寻找[i， n)之间的最小值
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }

    return;
}

int main()
{
    int a[10] = {10,9,8,6,7,5,4,3,1,2};
    selectionSort(a, 10);
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
