#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
//网络流重点：容量，流量，增广路，残留网
//dinic算法，可以一次累加多条增广路的流量
//bfs对点分层，找增广路
//dfs多路增广
//1.搜索顺序优化(分层限制搜索深度)
//2.当前弧优化(剪枝)
//3.剩余流量优化(剪枝)
//4.残枝优化(剪枝)
int n,m,s,t;
const int maxn=1000;
const int maxm=maxn*maxn;
int h[maxn],to[maxm],ne[maxm],w[maxm],idx=2;
int cur[maxn],d[maxn];
int g[maxn][maxn];
void add(int a,int b,int c)
{
    to[idx]=b;w[idx]=c;ne[idx]=h[a];h[a]=idx++;
}
int bfs()
{
    memset(d,0,sizeof d);
    queue<int>q;
    q.push(s);d[s]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=h[u];i;i=ne[i])
        {
            int v=to[i];
            if(d[v]==0 && w[i])
            {
                d[v]=d[u]+1;
                q.push(v);
                if(v==t) return 1;
            }
        }
    }
    return 0;
}
int dfs(int u,int mf)//函数有两个return，一个是到终点的，一个是后续返回的
{
    //入
    if(u==t) return mf;//已经抵达终点，直接返回mf,mf就是到这个点最大的流量
    int sum=0;
    for(int i=cur[u];i;i=ne[i])//i从cur开始走，剪枝，要是一个点有多个邻边，之前走到哪里就从哪里继续
    //因为如果能走到走到这条边那么说明前面的边已经走完了
    {
        //下
        cur[u]=i;//当前弧优化
        int v=to[i];
        if(d[v]==d[u]+1 && w[i])//严格要求，v要是u下一层的点并且有容量
        {
            int f=dfs(v,min(mf,w[i]));
            //回
            w[i]-=f;
            w[i^1]+=f;
            mf-=f;
            sum+=f;
            if(mf==0) break;//剪枝
        }
    }
    //离
    if(sum==0) d[u]=0;//剪枝，到不了终点，那就把这个点抹了，没用
    return sum;
}
int dinic()
{
    int flow=0;
    while(bfs())//bfs分层
    {
        memcpy(cur,h,sizeof h);//重置cur
        flow+=dfs(s,1e9);
    }
    return flow;
}
vector<pair<int,int>>v;
void init()
{
    memset(h,0,sizeof h);
    idx=2;
    memset(g,0,sizeof g);
}
signed main()
{
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        for(int i=0;i<maxn;i++) v.clear();
        init();
        for(int i=m+1;i<=m+n;i++)
        {
            string s;cin>>s;
            int num=0;
            char c=getchar();
            while(c!='\n')
            {
                if(c>='0' && c<='9')
                 num=num*10+(c-'0');
                else
                {
                    num++;
                    v.push_back({i,num});
                    num=0;
                }
                c=getchar();
            }
        }
        s=0,t=n+m+1;
        int l=0,r=1e9;
        int ans=1e9;
        while(l<=r)
        {
            int mid=l+r>>1;
            for(int i=m+1;i<=m+n;i++)
            {
                add(s,i,1); add(i,s,0);
            }
            for(int k=0;k<v.size();k++)
            {
                int x=v[k].first,y=v[k].second;
                add(x,y,1);add(y,x,0);
            }
            for(int i=1;i<=m;i++)
            {
                add(i,t,mid);add(t,i,0);
            }
            if(dinic()==n)
            {
                ans=mid;
                r=mid-1;
            }
            else
             l=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}