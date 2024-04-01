#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int maxn=500005;
unordered_map<string,int>mp;
int ans;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	string t;
	cin>>t;
	ans=0;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		mp[s]++;
	}
	for(auto n1:mp)
	{
		for(auto n2:mp)
		{
			string a=n1.first,b=n2.first;
			string cp=a+b;
			int p1=0,p2=0;
			while(p1<t.size() && p2<cp.size())
			{
				if(t[p1]==cp[p2])
				{
					p1++;
				}
				p2++;
			}
			if(p1==t.size())
			 ans+=n1.second*n2.second;
		}
	}
	cout<<ans<<endl;
	return 0;
}
//jttcoder
// atcoder
