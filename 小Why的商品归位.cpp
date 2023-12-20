#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin,tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
int a[maxn]; 
signed main()
{
	int n,m,k;
	cin>>n>>m>>k;
	memset(a,0,sizeof a);
	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;
		a[l]++;
		a[r]--;
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
		maxn=max(maxn,a[i]);
	}
	if(maxn<k)
	{
		cout<<1<<endl;
	}
	else
	{
		if(maxn%k==0)
		{
			cout<<maxn/k<<endl;
		}
		else
		{
			cout<<maxn/k+1<<endl;
		}
	}
	return 0;
}

