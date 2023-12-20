#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=400000;
int f[maxn];//d表示到父节点的距离 
set<int>st;
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
	st.clear();
}
int find(int x)
{
	if(x==f[x])
	 return x;
	else
	 return f[x]=find(f[x]);
	
}
void join(int x,int y)
{
	int ex=find(x);
	int ey=find(y);
	if(ex!=ey)
	 f[ex]=ey;
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		init();
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			join(a,b);
		}
		for(int i=1;i<=n;i++)
		 st.insert(find(i));
		cout<<st.size()<<endl;
	}
	return 0;
}
