#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;	
int f1[maxn][22],f2[maxn][22];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>f1[i][0];
		f2[i][0]=f1[i][0];
	}
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i+(1<<j)-1<=n+m-1;i++)
		 f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
		for(int i=1;i+(1<<j)-1<=n+m-1;i++)
		 f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
	}
	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;
		int k=log2(r-l+1);
		cout<<max(f1[l][k],f1[r-(1<<k)+1][k])-min(f2[l][k],f2[r-(1<<k)+1][k])<<endl;
	}
	return 0;
}
