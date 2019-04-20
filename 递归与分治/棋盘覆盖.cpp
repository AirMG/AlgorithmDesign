#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace chrono;

// L型骨牌标号
int tile = 1;
// 棋盘大小
int Board[10000][10000];

// tr左上角行号,tc左上角列号,dr特殊方格的行号,dc特殊方格的列号,size当前使用的棋盘大小
void chessBoard(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1)
        return;
    int t = tile++;
    int s = size / 2;
    //在左上角区域内
    if (dr < tr + s && dc < tc + s)
        chessBoard(tr, tc, dr, dc, s);
    //不在左上角区域内
    else
    {
        //用t号(用一个数字表示)L型骨牌覆盖右下角
        Board[tr + s - 1][tc + s - 1] = t;
        //覆盖剩余方格
        chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    //覆盖右上角子棋盘
    if (dr < tr + s && dc >= tc + s)
        chessBoard(tr, tc + s, dr, dc, s);
    //不在右上角的区域内
    else
    {
        Board[tr + s - 1][tc + s] = t;
        chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }
    if (dr >= tr + s && dc < tc + s)
        chessBoard(tr + s, tc, dr, dc, s);
    else
    {
        Board[tr + s][tc + s - 1] = t;
        chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }
    // 覆盖右下角子棋盘
    if (dr >= tr + s && dc >= tc + s)
        chessBoard(tr + s, tc + s, dr, dc, s);
    else
    {
        Board[tr + s][tc + s] = t;
        chessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}

int main()
{
    int size;
    cout << "input size of chessboard" << endl;
    cin >> size;
    int x_index, y_index;
    cout << "input special chess location" << endl;
    cin >> x_index >> y_index;
    auto start = system_clock::now();
    chessBoard(0, 0, x_index - 1, y_index - 1, size);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "total time :" << double(duration.count()) / 1000 << "ms" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         cout << Board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}