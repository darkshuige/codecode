#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
map<int,int,greater<int> >mp,mp2;
signed main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		mp[k]++;
	}
	int k; cin>>k;
	int ma=mp[k];
	for(int i=1;i<=20;i++)
	{
		mp2=mp;
		for(auto d:mp)
		{
			int x=d.first,y=d.second;
			int xx;
			if(x%3==0) xx=x/3;
			else xx=x/3+1;
			int yy=y*2;
			mp2[x]-=y;
			if(mp2[x]==0) mp2.erase(x);
			mp2[xx]+=yy;
		}
		ma=max(ma,mp2[k]);
		mp=mp2;
	}
	cout<<ma<<endl;
	return 0;
}