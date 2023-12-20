#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
int flag[maxn];
int a[maxn];
signed main()
{
	jiasu;
	int n;
	memset(flag,0,sizeof flag);
	cin>>n;
	int sum=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>a[i];
		if(i!=0 && a[i-1]==0)
		{
			ans=max(ans,a[i]);
		}
		flag[a[i]]++;
		if(a[i]!=0)
		 sum++;
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]==0)
		 ans=max(ans,a[i]);
	}
	if(sum==0)
	 cout<<0<<endl;
	else
	{
		int pos=0;
		while(flag[pos]!=0) pos++;
		cout<<max(pos,ans)<<endl;
	}
	return 0;
}
