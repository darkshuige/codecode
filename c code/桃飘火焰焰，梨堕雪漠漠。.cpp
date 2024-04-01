#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
const int maxn=1005;
using namespace std;
int a[maxn];
signed main()
{
	jiasu;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	int sum=0;
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		sum+=a[op];
		a[op]=1000000;
	}
	if(k<=m)
	 cout<<sum<<endl;
	else
	{
		sort(a+1,a+1+n);
		for(int i=1;i<=k-m;i++)
		 sum+=a[i];
		cout<<sum<<endl;
	}
	return 0;	
} 
