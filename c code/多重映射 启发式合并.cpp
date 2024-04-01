#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1000005;
vector<int>dic[maxn];//dic(i)中存储所有要变为i的数
set<int>st;
int a[maxn],now[maxn];
signed main()
{
	jiasu;
	int t,n,m;
	cin>>t;
	while(t--)
	{
		st.clear();
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(!st.count(a[i]))
			 dic[a[i]].push_back(a[i]);
			st.insert(a[i]);
		}
		while(m--)
		{
			int f,t;
			cin>>f>>t;
			st.insert(f); st.insert(t);
			if(f==t) continue;
			if(dic[f].size()>dic[t].size())
			{
				for(auto to:dic[t])
				 dic[f].push_back(to);
				dic[t].clear();
				dic[t].shrink_to_fit();
				swap(dic[t],dic[f]);
			}
			else
			{
				for(auto to:dic[f])
				 dic[t].push_back(to);
				dic[f].clear();
				dic[f].shrink_to_fit();
			}
		}
		for(auto vv:st)
		 for(auto to:dic[vv])
		  now[to]=vv;
		for(int i=1;i<=n;i++)
		 cout<<now[a[i]]<<" ";
		cout<<endl;
		for(auto to:st)
		 dic[to].clear();
	}
	return 0;
} 
