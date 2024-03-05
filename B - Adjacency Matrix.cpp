#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200;
int a[maxn][maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			{
				cout<<j<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}