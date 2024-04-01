#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=400000;
struct node
{
	int u,v,w;
}a[maxn];
bool operator < (node a,node b)
{
	return a.w<b.w;
}
int f[maxn];
int n,m,ans;
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int cost[200][200];
int ku()
{
	int cnt=0;
	ans=0;
	for(int i=0;i<m;i++)
	{
		int ex=find(a[i].u);int ey=find(a[i].v);
		if(ex!=ey)
		{
			int pos=i+1;
			cnt++;
			while(pos<m)
			{
				int ex1=find(a[i].u);int ey1=find(a[i].v);
				int ex2=find(a[pos].u);int ey2=find(a[pos].v);
				if((ex1==ex2 && ey1==ey2) || (ex1==ey2 && ex2==ey1))
				{
					cost[ex][ey]=a[pos].w-a[i].w;
					break;
				}
				pos++;
			}	
			f[ex]=ey;
			ans+=a[i].w;
		}
	}
	return cnt==n-1;
}
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
	memset(cost,inf,sizeof cost);
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int kk=1;kk<=t;kk++)
	{
		cin>>n>>m;
		init();
		for(int i=0;i<m;i++)
		 cin>>a[i].u>>a[i].v>>a[i].w;
		sort(a,a+m);
		cout<<"Case #"<<kk<<" : ";
		if(ku())
		{
			int mi=inf;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				 mi=min(mi,cost[i][j]);
			}
			if(mi==inf)
			 cout<<"No second way"<<endl;
			else
			 cout<<ans+mi<<endl;	
		}
		else
		 cout<<"No way"<<endl;
	}
    return 0;
}
