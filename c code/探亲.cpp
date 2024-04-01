#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20005;
int f[maxn];
int n,m;
void init()
{
	for(int i=1;i<=n;i++)
	 f[i]=i;
}
int find(int x)
{
	if(f[x]!=x)
	 f[x]=find(f[x]);
	return f[x];
}
signed main()
{
	jiasu;
	cin>>n>>m;
	map<string,int>mp;
	int k=1;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if(!mp[s])
		 mp[s]=k++;
	}
	init();
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			string a,b;
			cin>>a>>b;
			int x=find(mp[a]),y=find(mp[b]);
			if(x!=y)
			{
				f[y]=x;
			}
		}
		else if(op==2)
		{
			string a,b;
			cin>>a>>b;
			int x=find(mp[a]),y=find(mp[b]);
			if(x==y)
			 cout<<1<<endl;
			else
			 cout<<0<<endl;
		}
	}
	return 0;
} 
