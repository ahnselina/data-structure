#ifndef SORT_TEST_HELPER
#define SORT_TEST_HELPER

#include <iostream>
#include <cassert>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

namespace SortTestHelper
{
    //����n��Ԫ�ص�������飬ÿ��Ԫ�ص������ΧΪ[range_l, range_r]
    int* generateRandomArray(int n, int range_l, int range_r)
    {
        int *arr = new int[n];

        srand(time(NULL));
        for(int i = 0; i < n; i++)
            arr[i] = rand()%(range_r - range_l + 1) + range_l;

        return arr;
    }

    //����һ���������������
    int* generateNearlySortedArray(int n, int swapTimes)
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


    //��������������Ԫ��
    int* copyArray(int arr[], int n)
    {
        int *a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = arr[i];

        return a;
    }


    //�ж������Ƿ�����
    template<typename T>
    bool isSorted(T arr[], int n)
    {
        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i+1] < arr[i])
                return false;
        }
        return true;
    }
    //��ӡ��������������
    template<typename T>
    void printArray(T arr[], int n)
    {
        for(int i = 0; i < n; i++)
            cout<<arr[i]<<"-- ";
        cout<<endl;

        return;
    }


    //���������㷨����ȷ�Ժ��㷨������ʱ��
    template<typename T>
    void testSort(const string &sortName, void (*sortAlgo)(T[], int), T arr[], int n)
    {
        clock_t startTime=clock();
        sortAlgo(arr, n);
        clock_t endTime=clock();
        cout<<sortName<<" : "<< double(endTime - startTime)/ CLOCKS_PER_SEC <<" s"<<endl;

        //cout<<"NUM: "<<n<<endl;
        //printArray(arr, n);
        assert(isSorted(arr, n));

        return;
    }

};

#endif // SORT_TEST_HELPER
