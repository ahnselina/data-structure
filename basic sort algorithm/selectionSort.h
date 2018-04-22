#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

using namespace std;

template<typename T>
void selectionSort(T a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }

    return;
}
#endif // SELECTION_SORT_H
