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
		int n,k; cin>>n>>k;
		string s; cin>>s;
		int x=0,y=0,ma=LLONG_MIN;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='U') y++;
			if(s[i]=='D') y--;
			if(s[i]=='L') x--;
			if(s[i]=='R') x++;
			ma=max(ma,abs(x-0)+abs(y-0));
		}
		k--;
		x=x*k,y=y*k;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='U') y++;
			if(s[i]=='D') y--;
			if(s[i]=='L') x--;
			if(s[i]=='R') x++;
			ma=max(ma,abs(x-0)+abs(y-0));
		}
		cout<<ma<<endl;
	}
	return 0;
} 	