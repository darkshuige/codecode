#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000;
int a[maxn][maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 for(int j=0;j<=i;j++)
	  cin>>a[i][j];
	for(int x=n-2;x>=0;x--)
	 for(int y=0;y<=x;y++)
	  a[x][y]+=max(a[x+1][y],a[x+1][y+1]);
	cout<<a[0][0]<<endl;
	return 0;
}