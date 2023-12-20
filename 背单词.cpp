#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=100005;
signed main()
{
	jiasu;
	int n,k;
	cin>>n>>k;
	map<string,int>mp;
	int cnt=0;
	int a[maxn];
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(!mp[s])
		 mp[s]=++cnt;
		a[i]=mp[s];
	}
	vector<int>v[maxn];
	for(int i=1;i<=n;i++)
	 v[a[i]].push_back(i);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(v[i].size()<2)
		 continue;
		for(int j=1;j<v[i].size();j++)
		{
			int l=j,r=v[i].size()-1,pos=-1;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(v[i][mid]-v[i][j-1]-1<=k)
				{
					pos=mid;
					l=mid+1;
				}
				else
				{
					r=mid-1;
				}
			}
			if(pos!=-1)
			 ans+=pos-j+1;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
