#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
int a[maxn];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	memset(a,-1,sizeof a);
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		a[op]=0;
	}
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]!=0)
		 a[i]=a[i+1]+1;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
