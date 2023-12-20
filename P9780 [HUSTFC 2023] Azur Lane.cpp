#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 6e6+5;
int a[maxn],b[maxn],t = -1,h;
const int inf = 1e9+5;
signed main()
{
	int m,k;
	cin>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		ans+=i;
	}
	b[m]=ans;
	int cnt=m-1;
	for(int i=m-1;i>=1;i--)
	{
		while(cnt>0 && a[cnt]<a[cnt+1])
		 cnt--;
		if(cnt==0)
		 b[i]=-1;
		else
		{
			ans-=cnt--;
			b[i]=ans;
		}
	}
	for(int i=1;i<=m;i++)
	 cout<<b[i]<<" ";
    return 0;
}
