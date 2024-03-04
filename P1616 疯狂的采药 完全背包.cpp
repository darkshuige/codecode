#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=10000005;
int f[maxn],w[maxn],c[maxn];
signed main()
{
	jiasu;
	int t,n;
	cin>>t>>n;
	for(int i=0;i<n;i++)
	 cin>>w[i]>>c[i];
	memset(f,0,sizeof f);
	int ma=0;
	for(int i=0;i<n;i++)
	{
		for(int j=w[i];j<=t;j++)
		{
			f[j]=max(f[j],f[j-w[i]]+c[i]);
			ma=max(ma,f[j]);
		}
	}
	cout<<ma<<endl;
    return 0;
}