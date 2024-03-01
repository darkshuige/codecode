#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1000005;
struct node
{
	int u,v,w;
}a[maxn];
int cmp(node a,node b)
{
	return a.w<b.w;
}
int f[maxn];
int n,m,ans,cnt;
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int ku()
{
	ans=0;
	int now=0;
	for(int i=0;i<cnt;i++)
	{
		int ex=find(a[i].u);int ey=find(a[i].v);
		if(ex!=ey)
		{
			f[ex]=ey;
			ans+=a[i].w;
			now++;
		}
		if(now==n-m) break;
	}
	return ans;
}
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
}
int kk[maxn];
signed main()
{
	jiasu;
	cin>>n>>m;
	init();
	cnt=0;
	for(int i=0;i<n;i++)
	 cin>>kk[i];
	sort(kk,kk+n);
	for(int i=0;i<n-1;i++)
	{
		a[cnt].u=i;
		a[cnt].v=i+1;
		a[cnt++].w=abs(kk[i]-kk[i+1]);
	}
	sort(a,a+cnt,cmp);
	cout<<ku()<<endl;
    return 0;
}
