#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=1000005;
int n,top;
struct node
{
	int rt;
	int r;
	int siz;
}s[maxn];
int lc[maxn],rc[maxn],dis[maxn],a[maxn],b[maxn];
int merge(int x,int y)//递归合并
{
	if(!x || !y) return x+y;
	if(a[x]<a[y]) swap(x,y);
	rc[x]=merge(rc[x],y);
//	fa[rc[x]]=x;
	if(dis[lc[x]]<dis[rc[x]]) swap(lc[x],rc[x]);
	dis[x]=dis[rc[x]]+1;
	return x;
}
int del(int x)
{
	return merge(lc[x],rc[x]);
}
signed main()
{
	jiasu;
	cin>>n; dis[0]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]-=i;
	}
	for(int i=1;i<=n;i++)
	{
		s[++top]={i,i,1};
		while(top>1 && a[s[top-1].rt]>a[s[top].rt])
		{
			s[top-1].rt=merge(s[top-1].rt,s[top].rt);
			s[top-1].r=s[top].r;
			s[top-1].siz+=s[top].siz;
			top--;	
			while(s[top].siz>(s[top].r-s[top-1].r)/2+1)
			{
				s[top].rt=del(s[top].rt);
				s[top].siz--;
			}
		} 	
	}
	for(int i=1,j=1;i<=top;i++)
	 while(j<=s[i].r) b[j++]=a[s[i].rt];
	int res=0;
	for(int i=1;i<=n;i++)
	 res+=abs(a[i]-b[i]);
	cout<<res<<endl;
	for(int i=1;i<=n;i++)
	 cout<<b[i]+i<<" ";
	return 0;
}