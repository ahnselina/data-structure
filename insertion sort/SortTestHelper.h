#ifndef SORT_TEST_HELPER
#define SORT_TEST_HELPER

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper
{
    //生成有n个元素的随机数组，每个元素的随机范围为[range_l, range_r]
    int *generateRandomArray(int n, int range_l, int range_r)
    {
        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i++)
            arr[i] = rand()%(range_r - range_l + 1) + range_l;
        return arr;
    }

    // 生成一个近乎有序的数组
    // 首先生成一个含有[0...n-1]的完全有序数组, 之后随机交换swapTimes对数据
    // swapTimes定义了数组的无序程度:
    // swapTimes == 0 时, 数组完全有序
    // swapTimes 越大, 数组越趋向于无序
    int *generateNearlyOrderedArray(int n , int swapTimes)
    {
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = i;

        srand(time(NULL));
        for(int i = 0; i < swapTimes; i++)
        {
            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx], arr[posy]);
        }

        return arr;
    }

    //拷贝整型数组a中的所有元素到一个新的数组，并返回新的数组
    int *copyIntArray(int a[], int n)
    {
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = a[i];

        return arr;
    }

    //打印数组中所有元素
    template<typename T>
    void printArray(int a[], int n)
    {
        for(int i = 0; i < n; i++)
            cout << a[i] <<" ";
        cout << endl;

        return;
    }

    //判断数组是否有序
    template<typename T>
    bool isSorted(T a[], int n)
    {
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] > a[i+1])
                return false;
        }

        return true;
    }

    //测试排序算法的正确性和算法运行的时间
    template<typename T>
    void testSort(const string &sortName, void(*sortAlgo)(T[], int), T arr[], int n)
    {
        clock_t startTime = clock();
        sortAlgo(arr, n);
        clock_t endTime = clock();
        cout << sortName << ":" << double(endTime - startTime)/CLOCKS_PER_SEC << " s"<<endl;

        assert(isSorted(arr, n));
        return;
    }

}


#endif // SORT_TEST_HELPER
