#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxf=10015;
const int maxn=550;
int f[maxf];
int w[maxn],c[maxn];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		m=m-n;
		cin>>n;
		memset(f,inf,sizeof f);
		f[0]=0;
		for(int i=1;i<=n;i++)
		 cin>>c[i]>>w[i];
		for(int i=1;i<=n;i++)
		 for(int j=w[i];j<=m;j++)
		  f[j]=min(f[j],f[j-w[i]]+c[i]);
		if(f[m]!=inf)
		 cout<<"The minimum amount of money in the piggy-bank is "<<f[m]<<"."<<endl;
		else
		 cout<<"This is impossible."<<endl;
	}
	return 0;
}