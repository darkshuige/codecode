#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=500005;
int ch[maxn][26],idx;
pair<int,int>cnt[maxn];
int ne[maxn];
string a[maxn];
map<string,int>mp;
int ans[maxn];
string s;
void insert(string s,int v)
{
	int p=0;
	for(int i=0;s[i];i++)
	{
		int j=s[i]-'a';
		if(!ch[p][j])
		 ch[p][j]=++idx;
		p=ch[p][j];
	}
	cnt[p].first++;
	cnt[p].second=v;
}
void build()
{
	queue<int>q;
	for(int i=0;i<26;i++)
	{
		if(ch[0][i])
		 q.push(ch[0][i]);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			int v=ch[u][i];
			if(v)//有就用父节点找回跳边，没有就找转移边 
			 ne[v]=ch[ne[u]][i],q.push(v);
			else
			 ch[u][i]=ch[ne[u]][i];
		}
	}
}
void query(string s)
{
	int p=0;
	for(int k=0;k<s.size();k++)
	{
		int j=s[k]-'a';
		p=ch[p][j];
		for(int i=p;i && ~cnt[i].first;i=ne[i])
		{
			ans[cnt[i].second]+=cnt[i].first;
			//cnt[i].first=-1;
		}
	}
}
signed main()
{
	int n;
	cin>>n;
	idx=0;
	int pos=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!mp.count(a[i]))
		 mp[a[i]]=pos++;
		insert(a[i],pos-1);
	}
	build();
	cin>>s;
	query(s);
	for(int i=1;i<=n;i++)
	 cout<<ans[mp[a[i]]]<<endl;
} 
