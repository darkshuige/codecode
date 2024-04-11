#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int a[maxn];
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		int res=0;
		res+=sum%n;
		sum=sum/n;
		int kk=res;
		int pos=1;
		while(kk)
		{
			if(a[pos]>sum)
			{
				int now=min(kk,a[pos]-sum);
				kk-=now;
				a[pos]-=(now);
			}
			pos++;
		}
		int ss=0;
		for(int i=1;i<=n;i++)
		 ss+=abs(a[i]-sum);
		res+=ss/2;
		cout<<res<<endl;
	}
	return 0;
}