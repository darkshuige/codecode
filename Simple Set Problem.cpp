#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int cmp(set<int>a,set<int>b)
{
	return *(a.begin())<*(b.begin());
}
void solve()
{
	map<int,int>cnt;
	vector<set<int> >v(maxn+1);
	set<int>st;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int sum;
		cin>>sum;
		for(int j=0;j<sum;j++)
		{
			int op;
			cin>>op;
			(v[i]).insert(op);
		}
	}
	sort(v.begin(),v.begin()+n,cmp);
	int ans;
	for(int i=0;i<n;i++)
	{
		st.insert(*(v[i].begin()));
		cnt[*(v[i].begin())]++;
	}
	ans=*(st.rbegin())-*(st.begin());
	vector<set<int> >::iterator it;
	for(it=v.begin();it!=v.end();it++)
	{
		set<int>sst=*it;
		int pp=sst.size();
		for(int k=0;k<pp-1;k++)
		{
			if(--cnt[*(sst.begin())]==0)
			 st.erase(*(sst.begin()));
			sst.erase(sst.begin());
			if(++cnt[*(sst.begin())]==1)
			 st.insert(*(sst.begin()));
			ans=min(ans,*(st.rbegin())-*(st.begin()));
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
