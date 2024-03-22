#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
const int maxn=300;
double f[maxn][2];
double g[maxn][2][2];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	int cnt=1;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		memset(f,0,sizeof f);
		f[0][0]=1;f[0][1]=0;
		for(int i=1;i<=n;i++)
		{
			f[i][0]=f[i-1][0]*(double)(n-i)/(n-i+1);
			f[i][1]=(f[i-1][0])*(double)1/(n-i+1)+f[i-1][1];
		}
		cout<<"Case #"<<cnt<<": "<<fixed<<setprecision(6)<<f[n-1][1]<<" ";
		g[0][0][]=1;g[0][1]=0;
		for(int i=1;i<=m;i++)
		{
			
		}
		cout<<fixed<<setprecision(6)<<g[m-1][1]<<endl;
	}
    return 0;
} 
