#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200000;
int f[maxn],w[maxn],c[maxn];
signed main()
{
	jiasu;
	int n,m;
	cin>>m>>n;
	for(int i=0;i<n;i++)
	 cin>>w[i]>>c[i];
	memset(f,0,sizeof f);
	int ma=INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
			f[j]=max(f[j],f[j-w[i]]+c[i]);
			ma=max(ma,f[j]);
		}
	}
	cout<<ma<<endl;
    return 0;
}