#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=110;
int g[maxn][maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	memset(g,0,sizeof g);
	for(int i=0;i<n;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int j=c;j<d;j++)
		{
			for(int k=a;k<b;k++)
			{
				g[j][k]++;
			}	
		}
	}
	int sum=0;
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		 if(g[i][j]!=0)
		  sum++;
	}
	cout<<sum<<endl;
	return 0;
}
