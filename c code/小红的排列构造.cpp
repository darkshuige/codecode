#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=100005;
int a[maxn];
signed main()
{
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	if(k>n || (k==n && k==1)) cout<<-1<<endl;
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=1) cout<<" ";
			if(i<=n-k) cout<<a[i];
			else if(i==n) cout<<a[n-k+1];
			else cout<<a[i+1];
		}
		cout<<endl;
	}
	return 0;
}

