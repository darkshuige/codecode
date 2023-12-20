#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=2005,maxm=6005;
int h[maxm],to[maxm],ne[maxm],tot=0;//邻接表 
int f[maxn];//存各个点的sg值
void add(int a,int b)
{
	to[++tot]=b,ne[tot]=h[a],h[a]=tot;
}
int sg(int u)
{
	if(f[u]!=-1)
	 return f[u];
	set<int>st;
	for(int i=h[u];i;i=ne[i])
	 st.insert(sg(to[i]));
	for(int i=0;;i++)
	 if(!st.count(i))
	  return f[u]=i;
} 
signed main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);	
	} 
	int s=0;
	memset(f,-1,sizeof f);
	for(int i=0;i<k;i++)
	{
		int x;
		cin>>x;
		s^=sg(x);
	}	
	if(s!=0)
	 cout<<"win"<<endl;
	else
	 cout<<"lose"<<endl;
	return 0;
}
