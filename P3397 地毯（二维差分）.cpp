#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
int a[maxn][maxn]={0};
signed main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1;i<=x2;i++)
		{
			a[i][y1]++;
			a[i][y2+1]--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]+=a[i][j-1];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
