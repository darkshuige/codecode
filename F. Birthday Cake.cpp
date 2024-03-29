#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=400005;
unordered_map<string,int>mp;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		mp[s]++;
	}
	int sum=0;
	for(auto i:mp)
	{
		for(auto j:mp)
		{
			if(i==j) continue;
			string s=i.first+j.first;
			if(s.substr(0,s.size()/2)==s.substr(s.size()/2,s.size()/2))
			 sum+=i.second*j.second;
		}
	}
	sum/=2;
	for(auto i:mp)
	 if(i.second>=2)
	  sum+=(i.second*(i.second-1)/2);
	cout<<sum<<endl;
	return 0;
}