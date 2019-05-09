#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include <cstring>

using namespace std;
using namespace chrono;

#define state 100

//存储路径的二维数组
int minPath[state + 1][state + 1];
void multiStageGraph(int stageNum, int *numPerStage)
{
    cout << "entry" << endl;
    int i, q, p, weight, temp;
    //初始化数组    
    memset(minPath, INT32_MAX, sizeof(minPath));
    //初始化源顶点层,源点为0
    for (p = 1; p <= numPerStage[0]; ++p)
    {
        minPath[0][p] = 0;
    }

    //按段计算，终止于汇顶点的前一段
    for (i = 1; i <= stageNum - 1; i++)
    {
        //对第i段中的每个顶点
        for (q = 1; q <= numPerStage[i]; q++)
        {
            //遍历获取对i+1段每个顶点的路径权值,同时计算累计权值,存储
            for (p = 1; p <= numPerStage[i + 1]; ++p)
            {
                //读取边(q,p)的权
                scanf("%d", &weight);
                //存在边(q,p)
                if (weight != -1)
                {
                    //COST(i,j)=min(c(i,j)+COST(i+1,l))
                    temp = weight + minPath[i][q];
                    //保存第i段中每个点到第i+1段中的点的路径的最小值
                    if (temp < minPath[i + 1][p])
                    {
                        minPath[i + 1][p] = temp;
                    }
                }
            }
        }
    }
    printf("%d\n", minPath[stageNum - 1][0]);
}

int main()
{
    int i, k, ni[state];
    //输入点层数
    while (scanf("%d", &k), k != -1)
    {

        for (i = 0; i < k; ++i)
        {
            //输入每一层的顶点数
            scanf("%d", &ni[i]);
        }
        cout << "Mark1" << endl;
        multiStageGraph(k, ni);
        cout << "Mark2" << endl;
    }
    return 0;
}
