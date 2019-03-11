#include <iostream>
#include <algorithm>

using namespace std;

// 用于翻转的函数
template <class T>
void Reverse(T array[], int from, int to)
{
    while (from < to)
    {
        swap(array[from], array[to]);
        from++;
        to--;
    }
}

/*
得到下一个排列
1.从后向前寻找第一个比后面的元素小的元素,记录下标
2.从后向前寻找比第一步找到的元素大的第一个元素,记录下标
3.交换两个元素
4.将第一步找到的元素之后的序列翻转
*/
template <class T>
bool Check(T array[], int len)
{
    int i, indexone, indextwo;
    for (i = len - 2; i >= 0; i--)
    {
        if (array[i] < array[i + 1])
        {
            indexone = i;
            break;
        }
    }
    // cout << indexone << endl;
    if (i < 0)
    {
        return false;
    }
    for (i = len - 1; i >= 0; i--)
    {
        if (array[i] > array[indexone])
        {
            indextwo = i;
            break;
        }
    }
    // cout << indexone << indextwo << endl
    swap(array[indexone], array[indextwo]);
    Reverse(array, indexone + 1, len - 1);
    return true;
}

// 全排列
template <class T>
void Perm(T array[], int len)
{
    if (array == NULL || len <= 0)
        return;
    sort(array, array + len);
    for (int i = 0; i < len; i++)
    {
        cout << array[i];
    }
    cout << endl;
    while (Check(array, len))
    {
        for (int i = 0; i < len; i++)
        {
            cout << array[i];
        }
        cout << endl;
    }
}

int main()
{
    int a[] = {1, 3, 3};
    Perm(a, end(a) - begin(a));
    return 0;
}