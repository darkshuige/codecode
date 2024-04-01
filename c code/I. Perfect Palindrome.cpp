#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=110;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		map<char,int>mp;
		mp.clear();
		int sum=INT_MIN;
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			mp[s[i]]++;
			sum=max(sum,mp[s[i]]);
		}
		cout<<s.size()-sum<<endl;
	}
	return 0;
}
