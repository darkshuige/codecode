#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int c[4],d[4],f[maxn],n,s;
void pack_pre()
{
	f[0]=1;
	for(int i=0;i<4;i++)
	 for(int j=c[i];j<maxn;j++)
	  f[j]+=f[j-c[i]]; 
}
int calc(int s)
{
	int res=0;
	for(int i=1;i<(1<<4);i++)
	{
		int t=0,sign=-1;
		for(int j=0;j<4;j++)
		{
			if(i & (1<<j))
			{
				t+=c[j]*(d[j]+1);
				sign=-sign;
			}
		}
		if(s>=t)
		 res+=f[s-t]*sign;
	}
	return f[s]-res;
}
signed main()
{
	for(int i=0;i<4;i++) cin>>c[i];
	pack_pre();
	cin>>n;
	while(n--)
	{
		for(int i=0;i<4;i++) cin>>d[i];
		cin>>s;
		cout<<calc(s)<<endl;
	}
	return 0;
}