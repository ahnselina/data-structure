#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <ctime>

using namespace std;

template<typename T>
int __Qpartition(T a[], int l, int r)
{
    swap(a[l], a[rand()%(r-l+1)+l]);
    T v = a[l];
    //[l+1, j] < v; [j+1, i) > v
    int j = l;
    for(int i = l + 1; i <= r; i++)
    {
        if(a[i] < v)
        {
            j++;
            swap(a[j], a[i]);
        }
    }
    swap(a[l], a[j]);

    return j;
}

template<typename T>
void __quickSort(T a[], int l, int r)
{
    if(l >= r)
    {
        return;
    }

    int p = __Qpartition(a, l, r);
    __quickSort(a, l, p-1);
    __quickSort(a, p+1, r);

    return;
}

template<typename T>
void quickSort(T a[], int n)
{
    srand(time(NULL));
    __quickSort(a, 0, n-1);
    return;
}

template<typename T>
int __partition2Ways(T a[], int l, int r)
{
    swap(a[l], a[rand()%(r-l+1)+l]);
    T v = a[l];
    //[l+1, i) < v; (j, r] > v
    int i = l + 1;
    int j = r;
    while(true)
    {
        while(i <= r && a[i] < v)
        {
            i++;
        }

        while(j >= l+1 && a[j] > v)
        {
            j--;
        }
        if (i > j)
        {
            break;
        }
        swap(a[i], a[j]);
        i++;
        j--;
    }
    swap(a[l], a[j]);

    return j;
}


template<typename T>
void __quickSort2Ways(T a[], int l, int r)
{
    if(l >= r)
    {
        return;
    }
    int p = __partition2Ways(a, l, r);
    __quickSort2Ways(a, l, p-1);
    __quickSort2Ways(a, p+1, r);


    return;
}

template<typename T>
void quickSort2Ways(T a[], int n)
{
    srand(time(NULL));
    __quickSort2Ways(a, 0, n-1);

    return;
}

template<typename T>
void __quickSort3Ways(T a[], int l, int r)
{
    if(l >=r )
    {
        return;
    }
    swap(a[l], a[rand()%(r-l+1)+l]);
    T v = a[l];
    //[l+1, lt] < v; [lt+1, i) == v; [gt, r] > v
    int lt = l;
    int gt = r + 1;
    int i = l + 1;
    while(i < gt)
    {
        if(a[i] < v)
        {
            swap(a[i], a[lt+1]);
            lt++;
            i++;
        }
        else if(a[i] > v)
        {
            swap(a[i], a[gt-1]);
            gt--;
        }
        else
        {
            i++;
        }
    }
    swap(a[l], a[lt]);

    __quickSort3Ways(a, l, lt-1);
    __quickSort3Ways(a, gt, r);

    return;
}

template<typename T>
void quickSort3Ways(T a[], int n)
{
    srand(time(NULL));
    __quickSort3Ways(a, 0, n-1);

    return;
}
#endif // QUICK_SORT_H
