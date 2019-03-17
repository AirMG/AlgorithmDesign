#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

// 设置数组的大小为100000
#define SIZE 200000

// 二分查找函数递归实现
int BinarySearch_r(int arr[], int N, int left, int right)
{
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == N)
        {
            return mid;
        }
        else if (arr[mid] < N)
        {
            return BinarySearch_r(arr, N, mid + 1, right);
        }
        else if (arr[mid] > N)
        {
            return BinarySearch_r(arr, N, left, mid - 1);
        }
    }
    return -1;
}

// 二分查找函数非递归实现
int BinarySearch_notr(int arr[], int N, int Size)
{
    int low = 0;
    int high = Size - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == N)
        {
            return mid;
        }
        else if (arr[mid] < N)
        {
            low = mid + 1;
        }
        else if (arr[mid] > N)
        {
            high = mid - 1;
        }
    }
    return -1;
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
    sort(arr, arr + SIZE);

    auto start = system_clock::now();
    // N=15000
    // cout << BinarySearch_notr(arr, 15000, SIZE) << endl;
    cout << BinarySearch_r(arr, 15000, 0, SIZE) << endl;
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "total time of recursion funciton :" << double(duration.count()) * microseconds::period::num << "ms" << endl;
    return 0;
}