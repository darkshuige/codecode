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
#include<iomanip>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=300;
double x[maxn],y[maxn],d[maxn],mp[maxn][maxn];
int vis[maxn],n;
void djst(int s)
{
	memset(vis,0,sizeof vis);
	vis[s]=1;
	d[s]=0;
	for(int i=0;i<n;i++)
	 d[i]=mp[s][i];
	while(1)
	{
		double m=inf;
		int v=-1;
		for(int i=0;i<n;i++)
		{
			if(vis[i]==0 && d[i]<m)
			{
				v=i;
				m=d[i];
			}
		}
		if(v==-1) break;
		vis[v]=1;
		if(vis[1]==1) break;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==0 && max(d[v],mp[v][j])<d[j])
			{
				d[j]=max(d[v],mp[v][j]);
			}
		}
	}
}
signed main()
{
	jiasu;
	cout<<fixed<<setprecision(3);
	int cnt=1;
	while(cin>>n)
	{
		if(n==0) break;
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		memset(mp,0,sizeof mp);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				double sum=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				mp[i][j]=mp[j][i]=sum;
			}
		}
		djst(0);
		cout<<"Scenario #"<<cnt<<endl;
		cout<<"Frog dtance = "<<d[1]<<endl<<endl;
	}
	return 0;
}
