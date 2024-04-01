#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1010,maxm=200010;
int h[maxn],to[maxm],ne[maxm],w[maxm],tot;
int rh[maxn];//rh��ʾ��ͼ 
int n,m,s,t,k;
void add(int h[],int a,int b,int c)
{
	w[tot]=c;to[tot]=b;ne[tot]=h[a];h[a]=tot++;
}
int f[maxn],vis[maxn];
void djst()
{
	memset(f,inf,sizeof f);
	f[t]=0;
	memset(vis,0,sizeof vis);
	priority_queue<pair<int,int> >q; //pair ��һ���ž��룬�ڶ����ŵ�
	q.push(make_pair(0,t));
	while(!q.empty())
	{
		pair<int,int>t=q.top();q.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=rh[u];i;i=ne[i])//ö��u�����еĳ��� 
		{
			int v=to[i];//�����ﵽ�ĵ� 
			if(f[u]+w[i]<f[v])
			{
				f[v]=f[u]+w[i];
				q.push(make_pair(-f[v],v));//���ȶ���Ĭ�ϴ����				
			}
		}
	}
}
struct node
{
	int s,v,d;
	bool operator<(const node &x)const
	{
		return s>x.s;//����s����s����ʵ�ʾ������Ԥ�����룬��������+���� 
	}
};
int cnt[maxn];//��ʾһ��������еĴ������ڼ��γ����ǵڼ�С
int astar()
{
	priority_queue<node>q;
	node a={f[s],s,0};
	q.push(a);
	while(!q.empty())
	{
		node op=q.top();q.pop();
		int u=op.v;
		cnt[u]++;
		if(cnt[t]==k) return op.d;
		for(int i=h[u];i;i=ne[i])
		{
			int v=to[i];
			int d=op.d+w[i];
			int s=d+f[v];
			if(cnt[v]<k)
			{
				node sb={s,v,d};
				q.push(sb);	
			}
			 
		}
	}
	return -1;
}
signed main()
{
	cin>>n>>m;
	tot=1;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(h,x,y,z);add(rh,y,x,z);
	}
	cin>>s>>t>>k;
	if(s==t) k++;
	djst();
	cout<<astar()<<endl;
	return 0;
} 
