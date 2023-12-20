#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int maxn=120;
int mp[maxn][maxn];
int n,m;
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>mp[i][j];
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  mp[i][j]+=(mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1]);
	int ans=0;
	for(int k=1;k<=min(n,m);k++)
	 for(int i=k;i<=n;i++)
	  for(int j=k;j<=m;j++)
	   if(mp[i][j]-mp[i-k][j]-mp[i][j-k]+mp[i-k][j-k]==k*k)
	    ans=max(ans,k);
	cout<<ans<<endl;
	return 0;
}
