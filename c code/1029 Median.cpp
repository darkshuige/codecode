#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
vector<int>v;
signed main()
{
	int n1; cin>>n1;
	for(int i=0;i<n1;i++)
	{
		int k; cin>>k;
		v.push_back(k);
	}
	int n2; cin>>n2;
	for(int i=0;i<n2;i++)
	{
		int k; cin>>k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	cout<<v[(n1+n2-1)/2]<<endl;
	return 0;
} 
