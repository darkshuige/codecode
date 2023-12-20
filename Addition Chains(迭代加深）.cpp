#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100010;
int n,d,a[maxn];
int dfs(int u)
{
	if(u==d) return a[u-1]==n;
	for(int i=u-1;i>=0;i--)
	{
		int t=a[u-1]+a[i];
		if(t>n) continue;
		a[u]=t;
		for(int j=u+1;j<=d;j++) t*=2;
		if(t<n) return 0;
		if(dfs(u+1)) return 1;
	}
	return 0;
}
signed main()
{
	a[0]=1;
	while(cin>>n)
	{
		if(n==0)
		 return 0;
		d=1;
		while(!dfs(1)) d++;
		for(int i=0;i<d;i++)
		{
			if(i!=0)
			 cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
} 
