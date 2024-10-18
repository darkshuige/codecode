#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=100005;
const int mod=1000000007;
int a[maxn];
signed main() 
{
    jiasu;
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	string s; cin>>s;
	int sum=0;
	int now=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='L')
		{
			if(now!=1)
			{
				now--;
			}
		}
		else if(s[i]=='R')
		{
			if(now!=n)
			{
				now++;
			}
		}
		sum=(sum%mod+a[now]%mod)%mod;
	}
	cout<<sum<<endl;
    return 0;
}
