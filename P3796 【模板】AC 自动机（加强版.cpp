#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=300010;
int ch[maxn][26],cnt[maxn],idx;
int ne[maxn];
string mob[maxn];
int ans[maxn];
string s;
void insert(string s,int v)//构建trie 
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		int j=s[i]-'a';
		if(!ch[p][j])
		 ch[p][j]=++idx;
		p=ch[p][j];
	}
	cnt[p]=v;
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
			 ne[v]=ch[ne[u]][i],q.push(v);//构建回跳边 
			else
			 ch[u][i]=ch[ne[u]][i];//转移边 
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
		for(int i=p;i;i=ne[i])//~表示取反，-1取反就是0000 
		{
			ans[cnt[i]]++;
		}
	}
}
signed main()
{
	int n;
	while(cin>>n)
	{
		memset(ne,0,sizeof ne);
		memset(cnt,0,sizeof cnt);
		memset(ch,0,sizeof ch);
		memset(ans,0,sizeof ans);
		idx=0;
		if(n==0)
		 break;
		for(int i=1;i<=n;i++)//必须从1开始，很多没有的默认是0算到0里面 
		{
			cin>>mob[i];
			insert(mob[i],i);
		}
		build();
		cin>>s;
		query(s);
		int temp=0;
        for(int i=1;i<=n;i++)
		 if(ans[i]>temp)
		  temp=ans[i];
        cout<<temp<<endl;
        for(int i=1;i<=n;i++)
		 if(ans[i]==temp)
		  cout<<mob[i]<<endl;
	}
	
} 
