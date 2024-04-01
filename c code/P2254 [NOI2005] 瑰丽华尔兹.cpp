#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=300;
struct node
{
	int f,pos;//最长距离f，第几个pos
};
deque<node>de;
int n,m,x,y,k;
int f[maxn][maxn];
int ex[]={+0,-1,+1,+0,+0};
int ey[]={+0,+0,+0,-1,+1};
char mp[maxn][maxn];
  //起始位置，行列长度，时区长度，方向d
int ans;
void dp(int x,int y,int l,int tim,int d)//外面的大循环循环时间，里面的循环队列，单调队列dp优化
{
	de.clear();
	for(int i=1;i<=l;i++)
	{
		int xx=x+ex[d]*(i-1),yy=y+ey[d]*(i-1);
		if(mp[xx][yy]=='x') de.clear();
		else
		{
			while(!de.empty() && de.back().f+i-de.back().pos<=f[xx][yy]) de.pop_back();
			de.push_back({f[xx][yy],i});
			if(de.front().pos<i-tim) de.pop_front();
			f[xx][yy]=de.front().f+i-de.front().pos;
			ans=max(ans,f[xx][yy]);
		}
		
	}
}
signed main()
{
	jiasu;
	cin>>n>>m>>x>>y>>k;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>mp[i][j];
	memset(f,-inf,sizeof f);
	f[x][y]=0;
	ans=LLONG_MIN;
	while(k--)//枚举时间点
	{
		int s,t,d;
		cin>>s>>t>>d;//枚举行列
		t=t-s+1;
		if(d==1) for(int i=1;i<=m;i++) dp(n,i,n,t,d);
		if(d==2) for(int i=1;i<=m;i++) dp(1,i,n,t,d);
		if(d==3) for(int i=1;i<=n;i++) dp(i,m,m,t,d);
		if(d==4) for(int i=1;i<=n;i++) dp(i,1,m,t,d);
	}
	cout<<ans<<endl;
	return 0;
}