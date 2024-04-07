#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=1000055;
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		string s; cin>>s;
		if(s.find("it")!=string::npos)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
} 
