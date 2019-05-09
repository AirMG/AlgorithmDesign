#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <stdlib.h>
#include <cmath>
#include <time.h>

#define SIZE 100

using namespace std;
using namespace chrono;

int linearTimeChoice(int key, int arr[], int len)
{
    // 结果
    int res = 0;
    // 如果数组长度小于0，返回
    if (len <= 0)
    {
        return 0;
    }
    // 如果长度小于5，直接使用sort排序后返回
    if (len < 5)
    {
        sort(arr, arr + len);
        res = arr[key - 1];
    }
    else
    {
        // 用于排序的二维数组
        int trans[len / 5][5];
        // 将一维数组转为二维数组
        for (int i = 0; i < len / 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                trans[i][j] = arr[i * 5 + j];
            }
        }
        // 存储每一列中位数的一维数组
        int mid[len / 5];
        for (int i = 0; i < len / 5; i++)
        {
            // 对二维数组的每一列进行排序
            sort(trans[i], trans[i] + 5);
            // 取中位数放到中位数数组中
            mid[i] = trans[i][2];
        }
        // 对中位数数组排序
        sort(mid, mid + len / 5);
        // 取所有中位数的中位数
        int midnum = mid[len / 5 / 2];
        // 三个部分数组
        int s1[len], s2[len], s3[len];
        int index1 = 0, index2 = 0, index3 = 0;
        // 根据和midnum的大小关系将二维数组中的元素转到三个部分数组中
        for (int i = 0; i < len; i++)
        {
            if (arr[i] < midnum)
            {
                s1[index1++] = arr[i];
            }
            else if (arr[i] == midnum)
            {
                s2[index2++] = arr[i];
            }
            else
                s3[index3++] = arr[i];
        }
        // 按照算法，根据key和三个部分数组的大小分情况进行处理
        if (key < index1 + 1)
        {
            res = linearTimeChoice(key, s1, index1);
        }
        else if (key > index1 + index2 + 1)
        {
            res = linearTimeChoice(key - index1 - index2, s3, index3);
        }
        else
            res = midnum;
    }
    // 返回最终结果
    return res;
}

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = i + 1;
    }
    random_shuffle(arr, arr + SIZE);
    int k = 0;
    cout << "input k:";
    cin >> k;
    auto start = system_clock::now();
    cout << linearTimeChoice(k, arr, SIZE) << endl;
    auto end = system_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "total time:" << double(duration.count()) / 1000 << "ms" << endl;
}