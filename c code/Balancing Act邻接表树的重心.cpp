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
using namespace std;
const int maxn=40005;
int vis[maxn];
int h[maxn],to[maxn],ne[maxn],idx;
int ans,n,pos;
void init()
{
	memset(h,-1,sizeof h);
	memset(vis,0,sizeof vis);
	idx=0;
	ans=INT_MAX;
}
void add(int a,int b)
{
	to[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
int dfs(int u)
{
	vis[u]=1;
	int sum=1;//��ʾ��uΪ���ڵ�һ���ж��ٸ��� 
	int size=0;//��ʾ���������ж��ٸ��� 
	for(int i=h[u];~i;i=ne[i])//���� 
	{
		int j=to[i];
		if(vis[j])
		 continue;
		int s=dfs(j);//����j������һ������ 
		sum+=s;
		size=max(size,s);
	}
	//	ans=min(ans,max(size,n-sum));//���������������������������������棬n-num��ʾ���棬size����������
	int mx=max(size,n-sum);
	if(mx<ans)
	{
		ans=mx;
		pos=u;
	}
	return sum;//dfs���ص��������һ���ж��ٸ��㣬�ڷ���֮ǰ�ж�һ��������ans 
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		init();
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}	
		dfs(1);
		cout<<pos<<" "<<ans<<endl;
	}
	return 0;
}
