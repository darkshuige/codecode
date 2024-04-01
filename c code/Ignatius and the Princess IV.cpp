#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
map<int,int>mp;
signed main()
{
	jiasu;
	int n;
	while(cin>>n)
	{
		mp.clear();
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			mp[x]++;
		}
		for(auto jj:mp)
		{
			if(jj.second>=(n+1)/2)
			{
				cout<<jj.first<<endl;
				break;
			}
		}
	}
	return 0;
}