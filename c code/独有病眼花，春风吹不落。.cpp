#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2005;
int n;
int a[maxn][maxn];
int f[maxn*maxn];
void init()
{
	for(int i=1;i<=n*n;i++)
	 f[i]=i;
}
int find(int x)
{
	if(f[x]!=x)
	 f[x]=find(f[x]);
	return f[x];
}
signed main()
{
	int m;
	cin>>n>>m;
	init();
	int flag=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		char op;
		cin>>x>>y>>op;
		int x2,y2;
		if(op=='D')
		{
			x2=x+1;
			y2=y;
		}
		else
		{
			y2=y+1;
			x2=x;
		}
		int pos1=(x-1)*n+y,pos2=(x2-1)*n+y2;
		int a=find(pos1),b=find(pos2);
		if(a!=b)
		 f[a]=b;
		else
		{
			cout<<i<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0)
	 cout<<"draw"<<endl;
	return 0;
}
