#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace chrono;

// 设置数组的大小为200000
#define SIZE 200000

void merge(int arr_source[], int low, int high)
{
    int *arr_result = new int[high - low];
    int mid = (low + high) / 2;
    int index = 0;
    int l_index = low;
    int r_index = mid;
    while (l_index < mid && r_index < high)
    {
        arr_result[index++] = arr_source[l_index] < arr_source[r_index] ? arr_source[l_index++] : arr_source[r_index++];
    }
    while (r_index < high)
    {
        arr_result[index++] = arr_source[r_index++];
    }
    while (l_index < mid)
    {
        arr_result[index++] = arr_source[l_index++];
    }
    int j = 0;
    for (int i = low; i < high; i++)
    {
        arr_source[i] = arr_result[j++];
    }
    delete[] arr_result;
}

void mergeSort(int arr[], int low, int high)
{
    if (low + 1 < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid, high);
        merge(arr, low, high);
    }
}

int main()
{
    int arr[SIZE] = {0};
    srand((unsigned)time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand();
        // cout << arr[i];
    }
    auto start = system_clock::now();
    mergeSort(arr, 0, SIZE);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "total time :" << double(duration.count()) / 1000 << "ms" << endl;
    return 0;
}