#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int maxn=5005;
int mp[maxn][maxn];
int n,m;
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		x++,y++;
		mp[x][y]+=z;
	}
	for(int i=1;i<=5001;i++)
	 for(int j=1;j<=5001;j++)
	  mp[i][j]+=(mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1]);
	int ans=0;
	for(int i=m;i<=5001;i++)
	 for(int j=m;j<=5001;j++)
	  ans=max(ans,(mp[i][j]-mp[i-m][j]-mp[i][j-m]+mp[i-m][j-m]));
	cout<<ans<<endl;
	return 0;
}
