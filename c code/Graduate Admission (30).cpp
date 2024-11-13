#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=40005;
int a[maxn];
struct person
{
	int ge,gi;
	int hop[10];
	int id;
}b[maxn];
vector<int>ans[maxn];
map<int,pair<int,int> >mp;
int cmp(person a,person b)
{
	if(a.ge+a.gi==b.ge+b.gi)
	 return a.ge>b.ge;
	else
	 return a.ge+a.gi>b.ge+b.gi;
}
signed main()
{
	int n,m,k; cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	 cin>>a[i];
	for(int i=0;i<n;i++)
	{
		b[i].id=i;
		cin>>b[i].ge>>b[i].gi;
		for(int j=0;j<k;j++)
		 cin>>b[i].hop[j];
	}
	sort(b,b+n,cmp);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(ans[b[i].hop[j]].size()<a[b[i].hop[j]])
			{
				ans[b[i].hop[j]].push_back(b[i].id);
				mp[b[i].hop[j]]={b[i].ge,b[i].gi};
				break;
			}
			else
			{
				if(b[i].ge==mp[b[i].hop[j]].first && b[i].gi==mp[b[i].hop[j]].second)
				{
					ans[b[i].hop[j]].push_back(b[i].id);
					break;
				}
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		sort(ans[i].begin(),ans[i].end());
		if(ans[i].size()==0) cout<<endl;
		else
		{
			int cnt=0;
			for(auto k:ans[i])
			{
				if(cnt!=0) cout<<" ";
				cnt++;
				cout<<k;
			}
			cout<<endl;
		}
	}
    return 0;
}
