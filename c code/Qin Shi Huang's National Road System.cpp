#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
//#define int long long
using namespace std;
#define ms(x, n) memset(x,n,sizeof(x));
typedef  long long LL;
const int inf = 1 << 30;
const LL maxn = 1010;
int N;
double w[maxn][maxn];
struct node 
{
    int x, y;
    int p;
    node(int xx, int yy, int pp) {x = xx, y = yy, p = pp;}
    node() {}
} vs[maxn];
double getDis(int x1, int y1, int x2, int y2) 
{
    return sqrt((double)(x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
double d[maxn];
bool used[maxn];
double maxD[maxn][maxn];   //MST中从i->j的最大权值
int pre[maxn];          //某一点父节点
bool mst[maxn][maxn];   //该点是否已经在MST中
typedef pair<int, int> P;
double Prim(int s) 
{
    fill(d, d + maxn, inf);
    fill(pre, pre+maxn, s);
    ms(maxD, 0); ms(used, 0); ms(mst, 0);
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(d[s] = 0, s));
    double res = 0;
    while(!q.empty()) 
	{
        P cur = q.top();
        q.pop();
        int u = cur.second;
        if(used[u])
            continue;
        used[u] = true, res += d[u];
        mst[u][pre[u]] = mst[pre[u]][u] = true; //加入到MST中
        for(int v = 1; v <= N; ++v) 
		{
            if(used[v] && w[u][v] < inf)        //只更新MST中的
                maxD[u][v] = maxD[v][u] = max(maxD[pre[u]][v], d[u]);
            if(w[u][v] < d[v]) 
			{
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
    scanf("%d",&T);
    while(T--) 
	{
        ms(vs, 0); fill(w[0], w[0]+maxn*maxn, inf);
        scanf("%d",&N);
        for(int i = 1; i <= N; ++i) 
		{
            scanf("%d%d%d",&a,&b,&c);
            vs[i] = node(a, b, c);
        }
        for(int i = 1; i < N; ++i)
            for(int j = i+1; j <= N; ++j)
                w[i][j] = w[j][i] = getDis(vs[i].x, vs[i].y, vs[j].x, vs[j].y);

        //枚举删边, 找出最大值
        double B = Prim(1), A, ans = -1;
        for(int i = 1; i < N; ++i)
            for(int j = i+1; j <= N; ++j)
			{
                A = vs[i].p+vs[j].p;
                //这条边未在MST中使用, 尝试加边并删去生成环中的最长边, 已使用则直接变0
                if(mst[i][j])
				{
                    ans = max(ans, A/(B-w[i][j]));
                }
				else
				{
                    ans = max(ans, A/(B-maxD[i][j]));
                }
            }
        printf("%.2lf\n", ans);
    }
    return 0;
}
