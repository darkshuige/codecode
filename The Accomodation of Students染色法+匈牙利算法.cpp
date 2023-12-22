#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000;
const int maxm=maxn*maxn;
//二分图:如果所有点可以分成两个集合并且集合中的点不相邻那就是二分图
//二分图之中只存在偶数环，不存在奇数环
//用dfs找到一个点，把他的邻点都变成和他不一样的颜色，如果找到一样颜色的邻点那么说明找到奇数边了
int h[maxn],to[maxm],ne[maxm],idx=1;
int color[maxn];
int vis[maxn],match[maxn];
void add(int a,int b)
{
    to[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
int dfs(int u,int c)//1和2交替
{
    color[u]=c;
    for(int i=h[u];i;i=ne[i])
    {
        int v=to[i];
        if(color[v]==0)
        {
        	if(dfs(v,3-c)) return 1;
		}
        else if(color[v]==c)
         return 1;
    }
    return 0;
}
int dfs2(int u)
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
        else if(dfs2(match[v]))//可以让出来
        {
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
void init()
{
    memset(h,0,sizeof h); idx=1;
    memset(color,0,sizeof color);memset(match,0,sizeof match);
}
signed main()
{
    jiasu;
    int n,m;
    while(cin>>n>>m)
    {
        init();
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            add(a,b);
            add(b,a);
        }
	    int flag=0;
	    for(int i=1;i<=n;i++)
	    {
	        if(color[i]==0)//未染色
	        {
	            if(dfs(i,1)==1)
	            {
	                flag=1;
	                break;
	            }
	        }
	    }
	    if(flag)
	     cout<<"No"<<endl;
	    else
	    {
	        int ans=0;
	        for(int i=1;i<=n;i++)
	        {
	            if(color[i]==2) continue;
	            memset(vis,0,sizeof vis);
	            if(dfs2(i)) ans++;
	        }
	        cout<<ans<<endl;
	    }
    }
    return 0;
}