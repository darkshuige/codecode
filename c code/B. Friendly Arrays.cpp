#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f
using namespace std;
const int maxn=200005;
int a[maxn],b[maxn],c[maxn];
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int maxn=0,minn=0;
		for(int i=0;i<n;i++)
		{
			int op;
			cin>>op;
			maxn^=op,minn^=op;
		}
		int ans=maxn;
		for(int i=0;i<m;i++)
		{
			int op;
			cin>>op;
			ans|=op;
			maxn=max(maxn,ans);
			minn=min(minn,ans);
		}
		cout<<minn<<" "<<maxn<<endl;
	} 
	return 0;
}
