#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout,tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000005;
int cnt[maxn*2];
int fa[maxn*2];
int ch[maxn*2][26];
int len[maxn*2];
int tot=1,np=1;
string str;
void extend(int c)
{
	int p=np;
	np=++tot;
	len[np]=len[p]+1; cnt[np]=1;//len��ʾ�ַ����ĳ���
	for(;p && !ch[p][c];p=fa[p])//һֱ��ǰ��ֱ���ҵ����ߵ�0
	 ch[p][c]=np;//��ת�Ʊ� 
	if(p==0) fa[np]=1;//���û�г��ֹ���fa=1�� 
	else//���ֹ� 
	{
		int q=ch[p][c];
		if(len[q]==len[p]+1)//��������� 
		 fa[np]=q;
		else//����������� 
		{
			int nq=++tot;//�ѿ� 
			len[nq]=len[p]+1;//ֱ����һ������ĵ� 
			fa[nq]=fa[q];
			fa[q]=nq;
			fa[np]=nq;
			for(;p && ch[p][c]==q;p=fa[p])
			 ch[p][c]=nq;
			memcpy(ch[nq],ch[q],sizeof ch[q]);
		}
	}
}
long long ans=0;
vector<int>e[maxn];
void dfs(int u)
{
	for(auto v:e[u])
	{
		dfs(v);
		cnt[u]+=cnt[v];
	}
	if(cnt[u]>1)
	 ans=max(ans,(long long)cnt[u]*len[u]);
}
signed main()
{
	cin>>str;
	for(int i=0;i<str.size();i++)
	 extend(str[i]-'a');
	for(int i=2;i<=tot;i++)//���룬���� 
	 e[fa[i]].push_back(i);
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
