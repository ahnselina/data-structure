#ifndef SHELL_SORT_H
#define SHELL_SORT_H

using namespace std;

template<typename T>
void shellSort(T a[], int n)
{
    int h = 1;
    while(h < n/3)
        h = h * 3 + 1;

    while(h >= 1)
    {
        for(int i = h; i < n; i++)
        {
            T e = a[i];
            int j;
            for(j = i; j >= h && a[j-h] > e; j -= h)
            {
                a[j] = a[j-h];
            }
            a[j] = e;
        }
        h /= 3;
    }
    return;
}
#endif // SHELL_SORT_H
