#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
struct HeadNode//ͷ��� 
{
    int d,u;//d��ʾ���룬u��ʾ�ĸ��� 
    bool operator < (const HeadNode& rhs) const//С����ǰ�� 
	{
        return d>rhs.d;
    }
}; 
struct edge//�� 
{
    int to;
    int cost;
};
vector<edge>g[10005];//��ʾһ�������е��ڽӱ� 
bool vis[10005];
int n,m,x,s,t;
int d[10005];
void djst()
{
    fill(d+1,d+n+1,M);
    d[s]=0;//sΪ0 
    priority_queue<HeadNode>q;
    q.push((HeadNode){0,s});//һ��ʼ����Ϊ0����Ϊs 
    while(!q.empty())
	{
        HeadNode x=q.top();q.pop();
        int u=x.u;
        if(vis[u])
		 continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++)
		{
            edge e=g[u][i];//�ڽӱ� 
            if(d[e.to]>d[u]+e.cost)
			{
                d[e.to]=d[u]+e.cost;
                q.push((HeadNode){d[e.to],e.to});
            }
        }
    }
}
signed main()
{
	jiasu;
    cin>>n>>m>>s>>t;//n��ʾ��ĸ�����mΪ�ߵĸ�����s����ʼ�㣬tΪ�յ� 
    for(int i=1;i<=m;i++)
	{
        edge e;
        cin>>x>>e.to>>e.cost;//x����ʼ�� 
        g[x].push_back(e);
    }
    djst();
    if(d[t]==M)
	 cout<<-1<<endl;
    else
	 cout<<d[t]<<endl;
    return 0;
} 
