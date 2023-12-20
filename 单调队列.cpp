#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
int a[maxn],p[maxn];
signed main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	int t=1,w=0;
	for(int i=1;i<=n;i++)
	{
		while(t<=w && a[i]<=a[p[w]])//尾部pop 
		 w--;
		p[++w]=i;//尾部push 
		if(p[t]<i-k+1) //头部pop 
		 t++;
		if(i>=k)
		 cout<<a[p[t]]<<" ";
	}
	cout<<endl;
	memset(p,0,sizeof p);
	t=1,w=0;
	for(int i=1;i<=n;i++)
	{
		while(t<=w && a[i]>=a[p[w]])
		 w--;
		p[++w]=i;
		if(p[t]<i-k+1)
		 t++;
		if(i>=k)
		 cout<<a[p[t]]<<" ";
	}
	cout<<endl;
	return 0;
}
