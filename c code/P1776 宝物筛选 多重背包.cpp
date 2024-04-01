#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int f[maxn],w[maxn],c[maxn];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int v1,w1,s;
		cin>>v1>>w1>>s;
		for(int j=1;j<=s;j<<=1)
		{
			c[cnt]=j*v1; w[cnt++]=j*w1;
			s-=j;
		}
		if(s)
		{
			c[cnt]=s*v1;  w[cnt++]=s*w1;
		}
	}
	memset(f,0,sizeof f);
	int ma=0;
	for(int i=0;i<cnt;i++)
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