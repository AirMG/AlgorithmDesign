#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace chrono;

#define ROW 1000
#define COL 1000

// 矩阵加法
void Add(int **matA, int **matB, int **matResult, int matLen)
{
    for (int i = 0; i < matLen; i++)
    {
        for (int j = 0; j < matLen; j++)
        {
            matResult[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

// 矩阵减法
void Sub(int **matA, int **matB, int **matResult, int matLen)
{
    for (int i = 0; i < matLen; i++)
    {
        for (int j = 0; j < matLen; j++)
        {
            matResult[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

// 矩阵乘法
void Mul(int **matA, int **matB, int **matResult)
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            matResult[i][j] = 0;
            for (int k = 0; k < 2; ++k)
            {
                matResult[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

// Strassen算法
void Strassen(int **matA, int **matB, int **matResult, int matLen)
{
    int halfmatLen = matLen / 2;

    // 用于存储矩阵块的矩阵
    int **a11 = new int *[halfmatLen];
    int **a12 = new int *[halfmatLen];
    int **a21 = new int *[halfmatLen];
    int **a22 = new int *[halfmatLen];

    int **b11 = new int *[halfmatLen];
    int **b12 = new int *[halfmatLen];
    int **b21 = new int *[halfmatLen];
    int **b22 = new int *[halfmatLen];

    int **s1 = new int *[halfmatLen];
    int **s2 = new int *[halfmatLen];
    int **s3 = new int *[halfmatLen];
    int **s4 = new int *[halfmatLen];
    int **s5 = new int *[halfmatLen];
    int **s6 = new int *[halfmatLen];
    int **s7 = new int *[halfmatLen];

    // 结果矩阵的分块矩阵
    int **matResult11 = new int *[halfmatLen];
    int **matResult12 = new int *[halfmatLen];
    int **matResult21 = new int *[halfmatLen];
    int **matResult22 = new int *[halfmatLen];

    // 在计算中使用的临时矩阵
    int **temp = new int *[halfmatLen];
    int **temp1 = new int *[halfmatLen];
    if (halfmatLen == 1)
    {
        Mul(matA, matB, matResult);
    }
    else
    {
        //矩阵分块
        for (int i = 0; i < halfmatLen; i++)
        {
            a11[i] = new int[halfmatLen];
            a12[i] = new int[halfmatLen];
            a21[i] = new int[halfmatLen];
            a22[i] = new int[halfmatLen];

            b11[i] = new int[halfmatLen];
            b12[i] = new int[halfmatLen];
            b21[i] = new int[halfmatLen];
            b22[i] = new int[halfmatLen];

            s1[i] = new int[halfmatLen];
            s2[i] = new int[halfmatLen];
            s3[i] = new int[halfmatLen];
            s4[i] = new int[halfmatLen];
            s5[i] = new int[halfmatLen];
            s6[i] = new int[halfmatLen];
            s7[i] = new int[halfmatLen];

            matResult11[i] = new int[halfmatLen];
            matResult12[i] = new int[halfmatLen];
            matResult21[i] = new int[halfmatLen];
            matResult22[i] = new int[halfmatLen];

            temp[i] = new int[halfmatLen];
            temp1[i] = new int[halfmatLen];
            for (int j = 0; j < halfmatLen; j++)
            {
                a11[i][j] = matA[i][j];
                a12[i][j] = matA[i][j + halfmatLen];
                a21[i][j] = matA[i + halfmatLen][j];
                a22[i][j] = matA[i + halfmatLen][j + halfmatLen];
                b11[i][j] = matB[i][j];
                b12[i][j] = matB[i][j + halfmatLen];
                b21[i][j] = matB[i + halfmatLen][j];
                b22[i][j] = matB[i + halfmatLen][j + halfmatLen];
            }
        }

        //计算s1
        Sub(b12, b22, temp, halfmatLen);
        Strassen(a11, temp, s1, halfmatLen);
        //计算s2
        Add(a11, a12, temp, halfmatLen);
        Strassen(temp, b22, s2, halfmatLen);
        //计算s3
        Add(a21, a22, temp, halfmatLen);
        Strassen(temp, b11, s3, halfmatLen);
        //计算s4
        Sub(b21, b11, temp, halfmatLen);
        Strassen(a22, temp, s4, halfmatLen);
        //计算s5
        Add(a11, a22, temp1, halfmatLen);
        Add(b11, b22, temp, halfmatLen);
        Strassen(temp1, temp, s5, halfmatLen);
        //计算s6
        Sub(a12, a22, temp1, halfmatLen);
        Add(b21, b22, temp, halfmatLen);
        Strassen(temp1, temp, s6, halfmatLen);
        //计算s7
        Sub(a11, a21, temp1, halfmatLen);
        Add(b11, b12, temp, halfmatLen);
        Strassen(temp1, temp, s7, halfmatLen);

        //计算matResult11
        Add(s5, s4, temp1, halfmatLen);
        Sub(temp1, s2, temp, halfmatLen);
        Add(temp, s6, matResult11, halfmatLen);
        //计算matResult12
        Add(s1, s2, matResult12, halfmatLen);
        //计算matResult21
        Add(s3, s4, matResult21, halfmatLen);
        //计算matResult22
        Add(s5, s1, temp1, halfmatLen);
        Sub(temp1, s3, temp, halfmatLen);
        Sub(temp, s7, matResult22, halfmatLen);

        //结果送回matResult中
        for (int i = 0; i < halfmatLen; i++)
        {
            for (int j = 0; j < halfmatLen; j++)
            {
                matResult[i][j] = matResult11[i][j];
                matResult[i][j + halfmatLen] = matResult12[i][j];
                matResult[i + halfmatLen][j] = matResult21[i][j];
                matResult[i + halfmatLen][j + halfmatLen] = matResult22[i][j];
            }
            // 释放块矩阵的空间
            delete (a11[i]);
            delete (a12[i]);
            delete (a21[i]);
            delete (a22[i]);

            delete (b11[i]);
            delete (b12[i]);
            delete (b21[i]);
            delete (b22[i]);

            delete (s1[i]);
            delete (s2[i]);
            delete (s3[i]);
            delete (s4[i]);
            delete (s5[i]);
            delete (s6[i]);
            delete (s7[i]);

            delete (matResult11[i]);
            delete (matResult12[i]);
            delete (matResult21[i]);
            delete (matResult22[i]);

            delete (temp[i]);
            delete (temp1[i]);
        }
        // 释放二维指针的空间
        delete (a11);
        delete (a12);
        delete (a21);
        delete (a22);

        delete (b11);
        delete (b12);
        delete (b21);
        delete (b22);

        delete (s1);
        delete (s2);
        delete (s3);
        delete (s4);
        delete (s5);
        delete (s6);
        delete (s7);

        delete (matResult11);
        delete (matResult12);
        delete (matResult21);
        delete (matResult22);

        delete (temp);
        delete (temp1);
    }
}

int main()
{
    int **mata = new int *[ROW];
    int **matb = new int *[ROW];

    srand((unsigned)time(NULL));

    for (int i = 0; i < ROW; i++)
    {
        mata[i] = new int[COL];
        matb[i] = new int[COL];
        for (int j = 0; j < COL; j++)
        {
            mata[i][j] = rand() % 10;
            matb[i][j] = rand() % 10;
        }
    }
    cout << "yes" << endl;

    int **matres = new int *[ROW];
    for (int i = 0; i < ROW; i++)
    {
        matres[i] = new int[COL];
    }
    cout << "start" << endl;
    auto start = system_clock::now();
    Strassen(mata, matb, matres, ROW);
    cout << "end" << endl;
    auto end = system_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "total time:" << double(duration.count()) / 1000 << "ms" << endl;
    // for (int i = 0; i < ROW; i++)
    // {
    //     for (int j = 0; j < COL; j++)
    //     {

    //         cout << matres[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}