#include <iostream>

using namespace std;

/*
思路
设被划分整数为n,用于划分的最大数设为n1,设最大数不大于m为q(n,m)
则  q(n,1)=1,即当m=1时,只有n=1+1...一种形式
    q(n,m)=q(n,n),m>=n,最大加数m实际上不能大于n
    q(n,n)=1+q(n,n-1)(m=n),当m等于n时,n的划分由n1=n以及n1<=n-1的划分组成,这里的1是最大加数等于n的那个划分
    q(n,m)=q(n,m-1)+q(n-m,m)n>m>1,当m<n时,n的最大加数n不大于m的划分由n1=m的划分和n1<=m-1的划分组成
*/

template <class T>
int Partition(T n, T m)
{
    if ((n < 1) || (m < 1))
        return 0;
    // 被划分的数为1或者最大加数为1,有1种划分
    if ((n == 1) || (m == 1))
        return 1;
    if (n < m)
        return Partition(n, n);
    else if (n == m)
        return Partition(n, m - 1) + 1;
    else if (m < n)
        return Partition(n, m - 1) + Partition(n - m, m);
}

int main()
{
    cout << Partition(8, 8) << endl;
    return 0;
}