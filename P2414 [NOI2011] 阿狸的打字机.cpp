#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=500005;
int ch[maxn][26],idx;
int cnt[maxn];
int ne[maxn];
string a[maxn];
string s,cp;
void init()
{
	idx=0;
	memset(ch,0,sizeof ch);
	memset(cnt,0,sizeof cnt);
	memset(ne,0,sizeof ne);
}
void insert(string s)
{
	int p=0;
	for(int i=0;s[i];i++)
	{
		int j=s[i]-'a';
		if(!ch[p][j])
		 ch[p][j]=++idx;
		p=ch[p][j];
	}
	cnt[p]++;
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
int query(string s)
{
	int ans=0;
	int p=0;
	for(int k=0;k<s.size();k++)
	{
		int j=s[k]-'a';
		p=ch[p][j];
		for(int i=p;i && ~cnt[i];i=ne[i])
		{
			ans+=cnt[i];
		}
	}
	return ans;
}
signed main()
{
	cin>>s;
	int pos=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='P')
		 a[pos++]=cp;
		else if(s[i]=='B')
		 cp=cp.substr(0,cp.size()-1);
		else
		 cp+=s[i];
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		init();
		insert(a[x]);
		build();
		cout<<query(a[y])<<endl;
	}
	return 0;
} 
