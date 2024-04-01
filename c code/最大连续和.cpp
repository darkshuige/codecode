#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
int a[maxn]={0},q[maxn],b[maxn];
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		a[i]=a[i-1]+b[i];
	}
	int t=0,w=0,ans=a[1];
	q[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(t<=w && q[t]<i-m)
		 t++;
		ans=max(ans,a[i]-a[q[t]]);
		while(t<=w && a[i]<=a[q[w]])
		 w--;
		q[++w]=i;
	}
	cout<<ans<<endl;
	return 0;
}
