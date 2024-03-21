#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=500;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	string s;
	cin>>s;
	s="#"+s;
	int p1,p2,l;
	cin>>p1>>p2>>l;
	string ans1=s,ans2=s;
	for(int i=0;i<l;i++)
	 ans1[p2+i]=ans1[p1+i];
	for(int i=0;i<l;i++)
	 ans2[p2+i]=s[p1+i];
	cout<<ans1.substr(1)<<endl<<ans2.substr(1)<<endl;
	return 0;
}