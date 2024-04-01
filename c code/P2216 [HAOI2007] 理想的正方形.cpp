#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1010,inf=1e9;
int w[maxn][maxn],minv[maxn][maxn],maxv[maxn][maxn];
deque<int>de;
int a[maxn],b[maxn],c[maxn],d[maxn];
int n,m,k;
// maxv[i][j]:第i行, j-k+1~j列的最大值
// a[i]:第i行, j-k+1~j列的最大值
// c[i]:第i-k+1~i行, j-k+1~j列的最大值
void get_max(int a[],int b[],int m)
{
	de.clear();
	for(int i=1;i<=m;i++)
	{
		while(!de.empty() && a[i]>=a[de.back()]) de.pop_back();
		de.push_back(i);
		if(de.front()<i-k+1) de.pop_front();
		b[i]=a[de.front()];
	}
}
void get_min(int a[],int b[],int m)
{
	de.clear();
	for(int i=1;i<=m;i++)
	{
		while(!de.empty() && a[i]<=a[de.back()]) de.pop_back();
		de.push_back(i);
		if(de.front()<i-k+1) de.pop_front();
		b[i]=a[de.front()];
	}
}
signed main()
{
	jiasu;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>w[i][j];
	for(int i=1;i<=n;i++)
	{
		get_max(w[i],maxv[i],m);
		get_min(w[i],minv[i],m);
	}
	int res=inf;
	for(int j=k;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=maxv[i][j];
			b[i]=minv[i][j];
		}
		get_max(a,c,n);
		get_min(b,d,n);
		for(int i=k;i<=n;i++)
		 res=min(res,c[i]-d[i]);
	}
	cout<<res<<endl;
	return 0;
}
