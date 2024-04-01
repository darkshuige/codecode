#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int f[maxn];
int n;
void init()
{
	for(int i=1;i<=n;i++)
	 f[i]=i;
}
int find(int x)
{
	if(x!=f[x])
	 f[x]=find(f[x]);
	return f[x];
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int m;
		cin>>n>>m;
		init();
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			int x=find(a),y=find(b);
			if(x!=y)
			f[y]=x;
		}
		int k;
		cin>>k;
		set<int>st;
		for(int i=0;i<k;i++)
		{
			int op;
			cin>>op;
			st.insert(find(op));
		}
		if(st.size()==1)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
}
