#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace chrono;

// 设置数组的大小为200000
#define SIZE 100000

int partitionSort(int arr[], int left, int right)
{
    int l_index = left + 1;
    int r_index = right;
    int key = arr[left];

    while (l_index <= r_index)
    {
        while (arr[l_index] < key)
        {
            l_index++;
        }
        while (arr[r_index] > key)
        {
            r_index--;
        }
        if (l_index < r_index)
        {
            swap(arr[l_index++], arr[r_index--]);
        }
        else
            l_index++;
    }
    swap(arr[r_index], arr[left]);
    return r_index;
}

void quickSort(int arr[], int left, int right)
{
    if (left > right)
    {
        return;
    }
    int mid = partitionSort(arr, left, right);
    quickSort(arr, left, mid - 1);
    quickSort(arr, mid + 1, right);
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
    quickSort(arr, 0, SIZE);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "total time " << double(duration.count()) / 1000 << "ms" << endl;
    return 0;
}