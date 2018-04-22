#include <iostream>
#include "SortTestHelper.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "shellSort.h"
#include "bubbleSort.h"
#include "mergeSort.h"
#include "quickSort.h"

using namespace std;

int main()
{
    int n = 50000;
    cout<<"Test for random array,size:"<<n<<" range [0, "<<n<<"]."<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyArray(arr1, n);
    int *arr3 = SortTestHelper::copyArray(arr1, n);
    int *arr4 = SortTestHelper::copyArray(arr1, n);
    int *arr5 = SortTestHelper::copyArray(arr1, n);
    int *arr6 = SortTestHelper::copyArray(arr1, n);
    int *arr7 = SortTestHelper::copyArray(arr1, n);
    int *arr8 = SortTestHelper::copyArray(arr1, n);
    SortTestHelper::testSort("select Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insert Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr4, n);
    SortTestHelper::testSort("Merge sort", mergeSort, arr5, n);
    SortTestHelper::testSort("Quick sort", quickSort, arr6, n);
    SortTestHelper::testSort("Quick sort 2 Ways", quickSort2Ways, arr7, n);
    SortTestHelper::testSort("Quick sort 3 ways", quickSort3Ways, arr8, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;

    // 测试2 近乎有序的数组
    n=50000;
    int swaptime=100;
    cout<<"Test for nearly ordered array,size:"<<n<<", swap time = "<<swaptime<<"."<<endl;
    arr1 = SortTestHelper::generateNearlySortedArray(n, swaptime);
    arr2 = SortTestHelper::copyArray(arr1, n);
    arr3 = SortTestHelper::copyArray(arr1, n);
    arr4 = SortTestHelper::copyArray(arr1, n);
    arr5 = SortTestHelper::copyArray(arr1, n);
    arr6 = SortTestHelper::copyArray(arr1, n);
    arr7 = SortTestHelper::copyArray(arr1, n);
    arr8 = SortTestHelper::copyArray(arr1, n);

    SortTestHelper::testSort("select Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insert Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr4, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr5, n);
    SortTestHelper::testSort("Quick sort", quickSort, arr6, n);
    SortTestHelper::testSort("Quick sort 2Ways", quickSort2Ways, arr7, n);
    SortTestHelper::testSort("Quick sort 3 ways", quickSort3Ways, arr8, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;

    // 测试3 测试存在包含大量相同元素的数组
    // 使用双快速排序后, 我们的快速排序算法可以轻松的处理包含大量元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyArray(arr1, n);
    arr3 = SortTestHelper::copyArray(arr1, n);
    arr4 = SortTestHelper::copyArray(arr1, n);
    arr5 = SortTestHelper::copyArray(arr1, n);
    arr6 = SortTestHelper::copyArray(arr1, n);
    arr7 = SortTestHelper::copyArray(arr1, n);
    arr8 = SortTestHelper::copyArray(arr1, n);
    SortTestHelper::testSort("select Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insert Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr4, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr5, n);
    SortTestHelper::testSort("Quick sort", quickSort, arr6, n);
    SortTestHelper::testSort("Quick sort 2Ways", quickSort2Ways, arr7, n);
    SortTestHelper::testSort("Quick sort 3 ways", quickSort3Ways, arr8, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    return 0;
}
