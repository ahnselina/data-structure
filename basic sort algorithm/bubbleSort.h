#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

using namespace std;

template<typename T>
void bubbleSort(T a[], int n)
{
    bool flag = true;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(a[j] > a[j+1])
            {
                flag = false;
                swap(a[j], a[j+1]);
            }
        }
        if(flag)
        {
            break;
        }
    }

    return;
}
#endif // BUBBLE_SORT_H
