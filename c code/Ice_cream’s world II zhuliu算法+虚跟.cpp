#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000;
int in[maxn],vis[maxn],id[maxn],pre[maxn];
struct edges
{
	int u,v,w;
}edge[maxn*maxn];
int n,m,pos,root,u,v,w,tot,sum,minroot;
int g[maxn][maxn];
int zhuliu(int root,int n)
{
    int res = 0;//res统计边权和。
    while(true)
	{
        for(int i = 0; i < n; ++ i) in[i] = INF, id[i] = vis[i] = -1;//初始化入边消耗等。
        for(int i = 0; i < tot; ++ i)
		{
            u = edge[i].u, v = edge[i].v, w = edge[i].w;
            if(u != v && w < in[v])
			{
                in[v] = w;
                pre[v] = u;
                if(u==root)
             	 minroot=i;
            }
        }
        for(int i = 0; i < n; ++ i)
		{
            if(i != root && in[i] == INF)
			{
                //说明不存在入边，无法构成树形图。
                return -1;
            }
        }
        in[root] = 0;
        
        int tn = 0;//新的编号。
        for(int i = 0; i < n; ++ i)
		{
            res += in[i];//统计入边消耗。
            v = i;
            while(vis[v] != i && id[v] == -1 && v != root)
			{
                vis[v] = i;
                v = pre[v];//不断迭代前驱结点，知道更新到根结点。若是环，当处于vis[v] = i时即会退出，即回到起点。
            }
            if(v != root && id[v] == -1)
			{
                //说明不是以root为根结点。即出现了有向环
                for(u = pre[v]; u != v; u = pre[u]) id[u] = tn;//重新给有向环编号，便于之后缩点。
                id[v] = tn++;//因为是从0开始编号所以这里是tn++不然是++tn和上面那句的位置也要翻一番 
            }
        }
        if(tn == 0)break;//说明没有重新编号，即不存在有向环。
        
        for(int i = 0; i <n; ++ i)
		{
            if(id[i] == -1)
			{
                id[i] = tn++;//给未重新编号的也重新编号，便于处理。
            }
        }
        int i = 0;
        while(i < tot)
		{
            int vv = edge[i].v;//由于入边还存着是原来的编号，所以这里取出入边终点。
            //获取重新的编号。
            edge[i].u = id[edge[i].u], edge[i].v = id[edge[i].v];
            if(edge[i].u != edge[i].v)
			{
                //这里看做是环外一点入环内的v点，所以我们需要减去环内入边权。
                //这样可以避免重复计算。
                edge[i].w -= in[vv];//更新权值，因为这个已经被累加了。
            }
            i++;
        }
        n = tn;//更新新的结点数量。
        root = id[root];//更新根结点编号。
    }
    return res;
}
void add(int a,int b,int c)
{
	edge[tot].u=a;
	edge[tot].v=b;
	edge[tot++].w=c;
}
signed main()
{
	jiasu;
	while(cin>>n>>m)
	{
		tot=sum=0;
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			add(a,b,c);
			sum+=c;
		}
		sum++;
		for(int i=0;i<n;i++)
		 add(n,i,sum);
		int ans=zhuliu(n,n+1);
		if(ans==-1 || ans>=2*sum)
		 cout<<"impossible"<<endl;
		else
		 cout<<ans-sum<<" "<<minroot-m<<endl;
		cout<<endl;
	}
	return 0;
}
