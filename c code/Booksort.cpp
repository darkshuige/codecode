#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;
int a[maxn],dep,n,b[5][maxn];
int f()
{
	int tot=0;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]!=a[i+1]-1)
		 tot++;
	}
	return (tot+2)/3;
}
int check()
{
	for(int i=0;i<n;i++)
	{
		if(a[i]!=i+1)
		 return 0;
	}
	return 1;
}
int dfs(int u)
{
	if(u+f()>dep) return 0;
	if(check()) return 1;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j,x,y;k<n;k++)
			{
				memcpy(b[u],a,sizeof a);
				for(x=j,y=i;x<=k;x++,y++)
				 a[y]=b[u][x];
				for(x=i;x<=j-1;x++,y++)
				 a[y]=b[u][x];
				if(dfs(u+1)) return 1;
				memcpy(a,b[u],sizeof a);
			}	
		}	
	}
	return 0;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		 cin>>a[i];
		for(dep=0;dep<5 && dfs(0)==0;dep++);
		if(dep>=5)
		 cout<<"5 or more"<<endl;
		else
		 cout<<dep<<endl;
	}
	return 0;
}
