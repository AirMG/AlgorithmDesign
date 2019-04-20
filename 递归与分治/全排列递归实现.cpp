#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

/*
将规模n的全排列转换为规模n-1的全排列
将规模n-1的全排列转换为规模n-2的全排列
以此类推
最后到规模1的全排列,即本身,递归的出口
*/

// 不带重复元素递归实现
template <class T>
void Perm(T array[], int k, int m)
{
    if (k == m)
    {
        for (int i = 0; i <= m; i++)
        {
            cout << array[i];
        }
        cout << endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            swap(array[k], array[i]);
            Perm(array, k + 1, m);
            swap(array[k], array[i]);
        }
    }
    return;
}

// 带重复元素全排列辅助函数
// 确保交换第p个和第i个元素之前,[p+1,i)区间内没有和第i个元素重复的元素
template <class T>
bool Back(T array[], int p, int i)
{
    if (p < i)
    {
        for (int j = p; j < i; j++)
        {
            if (array[j] == array[i])
                return false;
        }
    }
    return true;
}

// 带重复元素的全排列
// 从第一个元素开始和它后面的非重复元素交换
template <class T>
void PermRepeat(T array[], int k, int m)
{
    if (k == m)
    {
        for (int i = 0; i <= m; i++)
        {
            cout << array[i];
        }
        cout << endl;
        // cout << "跳出" << endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            if (Back(array, k, i))
            {
                // cout << "交换前k为" << k << endl;
                swap(array[k], array[i]);
                // cout << "k的值为" << k << endl;
                PermRepeat(array, k + 1, m);
                swap(array[k], array[i]);
            }
        }
    }
}

int main()
{
    int a[] = {2, 4, 3, 1};
    Perm(a, 0, 3);
    return 0;
}