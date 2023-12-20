#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2010;
int in[maxn],vis[maxn],id[maxn],pre[maxn];
//在有供水关系的人家间建边，构造超级源点0，从0向每户人家i建zi*X的边表示该户人家自己凿井的花费，之后就是求这张图的最小树形图了 
struct edges//加了虚点虚边就要<n n要变成n+1，并且++tn要变成tn++ 
{
	int u,v,w;
}edge[maxn*maxn];
struct node
{
	int x,y,z;
}a[maxn];
int n,m,pos,root,u,v,w,x,y,z;
int g[maxn][maxn];
int zhuliu(int root,int n,int m)
{
    int res = 0;//res统计边权和。
    while(true)
	{
        for(int i = 0; i<n; ++ i)in[i] = INF, id[i] = vis[i] = -1;//初始化入边消耗等。
        for(int i = 0; i < m; ++ i)
		{
            u = edge[i].u, v = edge[i].v, w = edge[i].w;
            if(u != v && w < in[v])
			{
                in[v] = w;
                pre[v] = u;
            }
        }
        for(int i = 0; i<n; ++ i)
		{
            if(i != root && in[i] == INF)
			{
                //说明不存在入边，无法构成树形图。
                return -1;
            }
        }
        in[root] = 0;
        
        int tn = 0;//新的编号。
        for(int i = 0; i<n; ++ i)
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
                for(u = pre[v]; u != v; u = pre[u])id[u] = tn;//重新给有向环编号，便于之后缩点。
                id[v] = tn++;
            }
        }
        if(tn == 0)break;//说明没有重新编号，即不存在有向环。
        
        for(int i = 0; i<n; ++ i)
         if(id[i] == -1)
          id[i] = tn++;//给未重新编号的也重新编号，便于处理。
        int i = 0;
        while(i < m)
		{
            int vv = edge[i].v;//由于入边还存着是原来的编号，所以这里取出入边终点。
            //获取重新的编号。
            edge[i].u = id[edge[i].u], edge[i].v = id[edge[i].v];
            if(edge[i].u != edge[i].v)
			{
                //这里看做是环外一点入环内的v点，所以我们需要减去环内入边权。
                //这样可以避免重复计算。
                edge[i++].w -= in[vv];//更新权值，因为这个已经被累加了。
            }
            else
			{
                //将有向环环边抛出。
                swap(edge[i],edge[--m]);
            }
        }
        n = tn;//更新新的结点数量。
        root = id[root];//更新根结点编号。
    }
    return res;
}
int dis(int i,int j)
{
	if(a[i].z>=a[j].z)
	 return y*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+abs(a[i].z-a[j].z));
	else
	 return y*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+abs(a[i].z-a[j].z))+z;
}
void add(int a,int b,int c)
{
	edge[m].u=a;
	edge[m].v=b;
	edge[m++].w=c;
}
signed main()
{
	jiasu;
	while(cin>>n>>x>>y>>z)
	{
		if(n==0 && x==0 && y==0 && z==0) break;
		memset(g,INF,sizeof g);
		for(int i=1;i<=n;i++)
		 cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=0;j<k;j++)
			{
				int op;
				cin>>op;
				int d=dis(i,op);//i->op 
				if(i==op) continue;
				g[i][op]=min(g[i][op],d);
			}
		}	
		m=0;
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)
		  if(g[i][j]!=INF)
		   add(i,j,g[i][j]);
		for(int i=1;i<=n;i++)
		 add(0,i,a[i].z*x);
		root=0;
		int ans=zhuliu(0,n+1,m);
		if(ans==-1)
		 cout<<"poor XiaoA"<<endl;
		else
		 cout<<ans<<endl;
	}
	return 0;
}
