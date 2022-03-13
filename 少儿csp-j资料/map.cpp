#include <iostream>
#include <vector>
#define MAXN 1005
using namespace std;
/**
 * 记录边的终点
 * 边权的结构体
 */
struct edge
{
    int to, cost;
};

int n, m; //表示图中有n个点，m条边
vector<edge> p[MAXN];

int v[MAXN][MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        p[u].push_back((edge){v, l});
        /**
         * 当无向图的邻接表需要加一条反方向的边
         * p[v].push_back((edge){u,l});
         *
         */
    }

    //把邻接表转换为邻接矩阵
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < p[i].size(); j++)
        {
            /* code */
        }
    }
}
