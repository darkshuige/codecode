#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn];
map<int,set<pair<int,int> > >mp;
signed main()
{
	jiasu;
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int sum=0;
	int l=1,r=1;
	while(!(l==r && r==n+1))
	{
		while(sum<m && r<=n)
		{
			sum+=a[r];
			r++;
		}
		mp[sum].insert({l,r-1});
		sum-=a[l]; l++;
		if(sum>=m)
		 mp[sum].insert({l,r-1});
	}
	auto it=mp.begin();
	for(it;(*it).first<m;it++);
	auto k=(*it).second;
	for(auto j:k)
	 cout<<j.first<<"-"<<j.second<<endl;
	return 0;
} 
