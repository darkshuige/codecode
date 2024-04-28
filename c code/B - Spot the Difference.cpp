#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
const int maxn=200;
char a[maxn][maxn];
signed main()
{
	jiasu;
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char x; cin>>x;
			if(x!=a[i][j])
			 cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}
