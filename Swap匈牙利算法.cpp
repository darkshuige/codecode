#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int maxn=200;
const int maxm=maxn*maxn;
//G为二分图，在G的子图中，任意两条边都没有公共节点，M就是G的匹配
//交替路，从一个未匹配点出发，一次经过匹配边，非匹配边
//增广路，从一个未匹配点除法，沿着交替路走，最后走到一个未匹配点
//那么增广路比交替路多了一条，只要交换增广路和匹配路，那么匹配路就多了一条
//匈牙利算法：通过不断找增广路来增加匹配边，dfs或bfs实现
//也可以用dinic算法，建立超级原点和汇点然后边权都是1
int h[maxn],to[maxm],ne[maxm],idx=1;
int vis[maxn],match[maxn];
int mat[maxn];
int a[maxn][maxn];
void add(int a,int b)
{
    to[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
int dfs(int u)
{
    for(int i=h[u];i;i=ne[i])
    {
        int v=to[i];
        if(vis[v]) continue;
        vis[v]=1;
        if(match[v]==0)//还没有匹配
        {
            match[v]=u;
            return 1;
        }
        else if(dfs(match[v]))//可以让出来
        {
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
vector<pair<int,int>>v;
void init()
{
    v.clear();
    memset(h,0,sizeof h); idx=1;
    memset(match,0,sizeof match);
    memset(mat,0,sizeof mat);
}
signed main()
{
    jiasu;
    int n;
    while(cin>>n)
    {
        init();
        for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
         {
            cin>>a[i][j];
            if(a[i][j]==1)
            {
                add(i,j);
                mat[i]=j;
            }
         }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof vis);
            if(dfs(i)) ans++;
        }
        if(ans!=n)
         cout<<-1<<endl;
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(mat[i]!=i)
                {
                    int j=1;
                    while(mat[j]!=i) j++;
                    v.push_back({i,j});
                    mat[j]=mat[i];mat[i]=i;
                }
            }
            cout<<v.size()<<endl;
            for(auto k:v)
             cout<<"R "<<k.first<<" "<<k.second<<endl;
        }
    }
    return 0;
}