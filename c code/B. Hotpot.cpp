#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
set<int>st;
int fa[maxn],ha[maxn];
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		st.clear(); memset(ha,0,sizeof ha);
		int n,k,m; cin>>n>>k>>m; //人数 配料数 move数量
		for(int i=0;i<n;i++) cin>>fa[i];
		int chu=m/(n*2),yu=m%(n*2);
		for(int i=0;i<min(n*2,m);i++)
		{
			int now=i%n;
			if(!st.count(fa[now]))
			 st.insert(fa[now]);
			else
			{
				st.erase(fa[now]);
				ha[now]++;
			}
		}
		if(chu>=1)
		{
			for(int i=0;i<n;i++) ha[i]*=chu;
			st.clear();
			for(int i=0;i<yu;i++)
			{
				int now=i%n;
				if(!st.count(fa[now]))
				 st.insert(fa[now]);
				else
				{
					st.erase(fa[now]);
					ha[now]++;
				}
			}	
		}
		for(int i=0;i<n;i++)
		{
			if(i!=0) cout<<" ";
			cout<<ha[i];
		}
		cout<<endl;
	}
	return 0;
}