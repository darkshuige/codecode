#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define ms(x, n) memset(x,n,sizeof(x));
typedef  long long LL;
const int inf = 1<<30;
const LL maxn = 110;

int N, M, w[maxn][maxn];
int d[maxn];
bool used[maxn];
int maxD[maxn][maxn];   //MST中从i->j的最大权值
int pre[maxn];          //某一点父节点
bool mst[maxn][maxn];   //该点是否已经在MST中
typedef pair<int, int> P;
int Prim(int s){
    fill(d, d+maxn, inf); ms(maxD, 0);
    ms(used, 0); ms(mst, 0);
    fill(pre, pre+maxn, s);
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(d[s]=0, s));
    int res = 0;
    while(!q.empty())
	{
        P cur = q.top();
        q.pop();
        int u = cur.second;
        if(used[u]) continue;
        used[u] = true, res += d[u];
        
        mst[u][pre[u]] = mst[pre[u]][u] = true; //加入到MST中
        for(int v = 1; v <= N; ++v)
		{
            if(used[v] && w[u][v]<inf)          //只更新MST中的
                maxD[u][v] = maxD[v][u] = max(maxD[pre[u]][u], d[u]);
            if(w[u][v] < d[v]){
                d[v] = w[u][v];
                pre[v] = u;                     //更新父节点
                q.push(P(d[v], v));
            }
        }
    }
    return res;
}

int main()
{
    int T, a, b, c;
    cin >> T;
    while(T--)
	{
        fill(w[0], w[0]+maxn*maxn, inf);
        cin >> N >> M;
        while(M--)
		{
            cin >> a >> b >> c;
            w[a][b] = w[b][a] = c;
        }
        int ans = Prim(1);
        bool flag = false;  //次小生成树是否等于最小生成树
        for(int u = 1; u <= N && !flag; ++u)
		{
            for(int v = 1; v <= N; ++v)
			{
                if(mst[u][v] || w[u][v]==inf)
                    continue;
                if(w[u][v] == maxD[u][v])
				{
                    flag = true;
                    break;
                }
            }
        }
        if(flag) cout << "Not Unique!\n";
        else cout << ans << endl;
    }
	return 0;
}
//首先说一下求解次小生成树的思路
//首先求出最小生成树，我们枚举每条不在最小生成树上的边，并把这条边放到最小生成树上面，然后就一定会形成环，那么我们在这条环路中取出一条最长的路（除了新加入的那一条边）。最终我们得到的权值就是次小生成树的权值。
//
//通过改写Prim和Kruskal都可以实现, 这里我是对Prim进行改写, 需要定义几个数组
//mst[i][j] : 表示该边是否已在MST中
//pre[i] : 表示 i 的父节点
//maxd[i][j] : 表示MST中从i -> j 的最大值
//
//这里的重点是如何求出maxd, 这里用到了动态规划的思想
//maxD[u][v] = max(maxD[pre[u]][u], d[u])
//
//而判断最小生成树是否等于次小生成树, 枚举所有未使用的边, 判断该边<i, j> 权值是否等于maxd[i][j]即可
//删的这条边必须是原来i,j两点的最大边，才有可能次小，如果求出来的要删的次小边与新添的边长度一样，那么就说明最小生成树不止一个。
