#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int f[maxn]; 
set<int>st;
vector<int>v;
int flag;
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
	flag=1;
	st.clear();
	v.clear();
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
	{
		f[ey]=ex;
	}
}
signed main()
{
	int a,b;
	init();
	while(cin>>a>>b)
	{
		if(a==-1 && b==-1) break;
		else if(a==0 && b==0)
		{
			for(auto i:v) st.insert(find(i));
			if(st.size()>1) flag=0;
			if(flag) cout<<"Yes"<<endl; else cout<<"No"<<endl;
			init();
		}
		else
		{
			v.push_back(a);v.push_back(b);
			int ex=find(a);int ey=find(b);
			if(ex==ey) flag=0; else join(a,b);
		}
	}
	return 0;
}
