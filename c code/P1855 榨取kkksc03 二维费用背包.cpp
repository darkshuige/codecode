#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=1000;
int f[maxn][maxn];
int w[maxn],v[maxn],c[maxn];
signed main()
{
	jiasu;
	int n,m,t;
	cin>>n>>m>>t;
	memset(f,0,sizeof f);
	for(int i=0;i<n;i++)
	 cin>>w[i]>>c[i];
	int ma=INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
			for(int k=t;k>=c[i];k--)
			{
				f[j][k]=max(f[j][k],f[j-w[i]][k-c[i]]+1);
				ma=max(ma,f[j][k]);
			}
		}
	}
	cout<<ma<<endl;
	return 0;
} 
