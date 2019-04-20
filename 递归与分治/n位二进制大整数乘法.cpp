#include <iostream>
#include <algorithm>
#include <chrono>
#include <string>
#include <cmath>

using namespace std;
using namespace chrono;

// 二进制加法
string binaryAdd(string a, string b, string c, string d)
{
    string ans;
    int len1 = a.length() - 1;
    int len2 = b.length() - 1;
    int len3 = c.length() - 1;
    int len4 = d.length() - 1;
    int num = 0;
    int carry = 0;
    while (len1 >= 0 || len2 >= 0 || len3 >= 0 || len4 >= 0)
    {
        num = carry;
        if (len1 >= 0)
            num += a[len1] - '0';
        if (len2 >= 0)
            num += b[len2] - '0';
        if (len3 >= 0)
            num += c[len3] - '0';
        if (len4 >= 0)
            num += d[len4] - '0';
        carry = num / 2;
        num %= 2;
        ans += (char)(num + '0');
        --len1;
        --len2;
        --len3;
        --len4;
    }
    while (carry)
    {
        ans += (char)(carry % 2 + '0');
        carry /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// 一般的二进制乘法
string binaryMulti(string s1, string s2)
{
    string ans;
    int len1 = s1.length();
    int len2 = s2.length();
    int num = 0;
    int carry = 0;
    if (len1 == 1)
    {
        for (int i = len2 - 1; i >= 0; --i)
        {
            num = carry + (s1[0] - '0') * (s2[i] - '0');
            carry = num / 2;
            num %= 2;
            ans += (char)(num + '0');
        }
        if (carry)
            ans += (char)(carry + '0');
    }
    else if (len2 == 1)
    {
        for (int i = len1 - 1; i >= 0; --i)
        {
            num = carry + (s2[0] - '0') * (s1[i] - '0');
            carry = num / 2;
            num %= 2;
            ans += (char)(num + '0');
        }
        if (carry)
            ans += (char)(carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// n位二进制乘法
string binaryBigMulti(string s1, string s2, int len1, int len2)
{
    if (s1.length() == 1 || s2.length() == 1)
    {
        return binaryMulti(s1, s2);
    }
    // 取字符串的一半
    int length1 = (len1 + 1) / 2;
    int length2 = (len2 + 1) / 2;
    // a
    string a = s1.substr(0, length1);
    // b
    string b = s1.substr(length1, len1 - length1);
    // c
    string c = s2.substr(0, length2);
    // d
    string d = s2.substr(length2, len2 - length2);

    // 计算中间值
    string num1 = binaryBigMulti(a, c, length1, length2);
    string num2 = binaryBigMulti(a, d, length1, len2 - length2);
    string num3 = binaryBigMulti(b, c, len1 - length1, length2);
    string num4 = binaryBigMulti(b, d, len1 - length1, len2 - length2);

    // 对数字补位
    num1.append(len1 + len2 - length1 - length2, '0');
    num2.append(len1 - length1, '0');
    num3.append(len2 - length2, '0');
    return binaryAdd(num1, num2, num3, num4);
}

int main()
{
    // 输入
    string Number1;
    string Number2;

    cout << "input first number" << endl;
    cin >> Number1;
    cout << "input second number" << endl;
    cin >> Number2;

    string res;
    auto start = system_clock::now();
    res = binaryBigMulti(Number1, Number2, Number1.length(), Number2.length());
    auto end = system_clock::now();
    cout << "result is: " << res << endl;
    auto duration = duration_cast<microseconds>(end - start);
    cout << "total time is:" << double(duration.count()) / 1000 << "ms" << endl;
    return 0;
}