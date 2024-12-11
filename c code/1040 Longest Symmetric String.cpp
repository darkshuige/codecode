#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=40005;
map<string,int>mp;
map<int,string>mp1;
vector<int>g[maxn];
signed main()
{
	jiasu;
	string s;
	getline(cin,s);
	int ans=1;
	for(int i=0;i<s.size();i++)
	{
		for(int j=i+1;j<s.size();j++)
		{
			string now=s.substr(i,j-i+1);
			string now2=now;
			reverse(now2.begin(),now2.end());
			if(now==now2)
			 ans=max(ans,(int)now.size());
		}
	}
	cout<<ans<<endl;
	return 0;
} 
