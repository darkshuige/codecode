#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=40005;
unordered_map<int,int>mp;
vector<int>v;
signed main()
{
	jiasu;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int k; cin>>k;
		v.push_back(k);
		mp[k]++;
	}
	int pos=-1;
	for(auto k:v)
	{
		if(mp[k]==1)
		{
			pos=k;
			break;
		}
	}
	if(pos==-1)
	 cout<<"None"<<endl;
	else
	 cout<<pos<<endl;
	return 0;
} 
