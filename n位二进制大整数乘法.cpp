#include <iostream>
#include <algorithm>
#include <chrono>

// 定义
// #define N 25

using namespace std;
using namespace chrono;

int *Func(int Number1[], int Number2[], int n)
{
    // 计算
    int a[n / 2] = {0};
    int b[n / 2] = {0};
    int c[n / 2] = {0};
    int d[n / 2] = {0};
    for (int i = 0; i < n / 2; i++)
    {
        a[i] = Number1[i];
        c[i] = Number2[i];
    }
    for (int i = n / 2; i < n; i++)
    {
        b[i] = Number1[i];
        d[i] = Number2[i];
    }

    // if(n==1){
    //     if()
    // }
}
int main()
{
    // 输入
    string Number1;
    string Number2;
    cout << "Input first number";
    cin >> Number1;
    cout << "Input second number";
    cin >> Number2;

    int sign = 0;
    int sign1 = 1;
    int sign2 = 1;
    // 处理符号
    if (Number1[0] == '-')
    {
        sign1 = -1;
        Number1.erase(Number1.begin());
    }
    if (Number2[0] == '-')
    {
        sign2 = -1;
        Number2.erase(Number2.begin());
    }
    sign = sign1 * sign2;

    int N = Number1.length();

    int number1[N] = {0};
    int number2[N] = {0};

    for (int i = 0; i < N; i++)
    {
        number1[i] = Number1[i];
    }
    for (int i = 0; i < N; i++)
    {
        number2[i] = Number2[i];
    }

    Func(number1, number2, N);

    return 0;
}