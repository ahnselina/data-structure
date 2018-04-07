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
    //������n��Ԫ�ص�������飬ÿ��Ԫ�ص������ΧΪ[range_l, range_r]
    int *generateRandomArray(int n, int range_l, int range_r)
    {
        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i++)
            arr[i] = rand()%(range_r - range_l + 1) + range_l;
        return arr;
    }

    // ����һ���������������
    // ��������һ������[0...n-1]����ȫ��������, ֮���������swapTimes������
    // swapTimes���������������̶�:
    // swapTimes == 0 ʱ, ������ȫ����
    // swapTimes Խ��, ����Խ����������
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

    //������������a�е�����Ԫ�ص�һ���µ����飬�������µ�����
    int *copyIntArray(int a[], int n)
    {
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = a[i];

        return arr;
    }

    //��ӡ����������Ԫ��
    template<typename T>
    void printArray(int a[], int n)
    {
        for(int i = 0; i < n; i++)
            cout << a[i] <<" ";
        cout << endl;

        return;
    }

    //�ж������Ƿ�����
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

    //���������㷨����ȷ�Ժ��㷨���е�ʱ��
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
