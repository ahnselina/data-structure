#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

using namespace std;

template<typename T>
void insertionSort(T a[], int n)
{
    for(int i = 1; i < n; i++)
    {
//        for(int j = i; j > 0 && a[j] < a[j-1]; j--)
//        {
//            swap(a[j], a[j-1]);
//        }
        T e = a[i];
        int j;
        for(j = i; j > 0 && a[j-1] > e; j--)
        {
            a[j] = a[j-1];
        }
        a[j] = e;
    }
    return;
}
#endif // INSERTION_SORT_H
