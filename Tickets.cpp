#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=4000;
int f[maxn],a[maxn],b[maxn];
signed main()
{
	jiasu;
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-1;i++) cin>>b[i];
		memset(f,inf,sizeof f);
		f[0]=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1]+a[i];
			if(i-1<=0) continue;
			f[i]=min(f[i],f[i-2]+b[i-1]);
		}
		int h=0,m=0,s=f[n];
		m+=s/60; s%=60;
		h+=m/60; m%=60;
		h+=8;
		cout<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<":"<<setw(2)<<setfill('0')<<s;
		if(h<=12) cout<<" am"<<endl;
		else cout<<" pm"<<endl;
	}
	return 0;
}