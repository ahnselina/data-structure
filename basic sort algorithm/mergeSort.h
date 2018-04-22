#ifndef MERGE_SORT_H
#define MERGE_SORT_H

using namespace std;

template<typename T>
void __merge(T a[], int l, int mid, int r)
{
    T aux[r-l+1];
    for(int i = l; i <= r; i++)
    {
        aux[i-l] = a[i];
    }

    int i = l;
    int j = mid + 1;
    for(int k = l; k <= r; k++)
    {
        if(i > mid)
        {
            a[k] = aux[j-l];
            j++;
        }
        else if(j > r)
        {
            a[k] = aux[i-l];
            i++;
        }
        else if(aux[i-l] < aux[j-l])
        {
            a[k] = aux[i-l];
            i++;
        }
        else
        {
            a[k] = aux[j-l];
            j++;
        }
    }

    return;
}

template<typename T>
void __mergeSort(T a[], int l, int r)
{
    if(l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    __mergeSort(a, l, mid);
    __mergeSort(a, mid+1, r);
    __merge(a, l, mid, r);

    return;
}

template<typename T>
void mergeSort(T a[], int n)
{
    __mergeSort(a, 0, n-1);
    return;
}

#endif // MERGE_SORT_H
