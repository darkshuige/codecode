#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1000005;
set<int>st;
map<int,int>mp;
int f[maxn][2];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int ma=LLONG_MIN;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ma=max(ma,x);
		st.insert(x);
		mp[x]++;
	}
	for(int i=1;i<ma;i+=2)
	{
		memset(f,0,sizeof f);
		f[i][1]=1;
		int mama=0;
		for(int j=i*2;j<=ma;j++)
		{
			f[j][0]=max(f[j/2][1],f[j/2][0]);
			f[j][1]=max(f[j][1],f[j/2][0]+mp[j]);
			mama=max(mama,max(f[j][0],f[j][1]));
		}
		sum+=mama;
	}
	cout<<n-sum<<endl;
	return 0;
}