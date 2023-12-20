#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
int ch[maxn][26],cnt[maxn],idx;
int ne[maxn];//ne放回跳边，ch放转移边 
char a[maxn];
void insert(char s[])
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
int query(char s[])
{
	int ans=0;
	int p=0;
	for(int k=0;s[k];k++)
	{
		int j=s[k]-'a';
		p=ch[p][j];
		for(int i=p;i && ~cnt[i];i=ne[i])
		{
			ans+=cnt[i];
			cnt[i]=-1;
		}
	}
	return ans;
}
signed main()
{
	int n;
	cin>>n;
	idx=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		insert(a);
	}
	build();
	char s[maxn];
	cin>>s;
	cout<<query(s)<<endl;
} 
