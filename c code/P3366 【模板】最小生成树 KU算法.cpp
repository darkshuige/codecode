#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=400000;
struct node
{
	int u,v,w;
}a[maxn];
bool operator < (node a,node b)
{
	return a.w<b.w;
}
int f[maxn];
int n,m,ans;
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int ku()
{
	int cnt=0;
	ans=0;
	for(int i=0;i<m;i++)
	{
		int ex=find(a[i].u);int ey=find(a[i].v);
		if(ex!=ey)
		{
			f[ex]=ey;
			ans+=a[i].w;
			cnt++;
		}
	}
	return cnt==n-1;
}
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
}
signed main()
{
	jiasu;
	cin>>n>>m;
	init();
	for(int i=0;i<m;i++)
	 cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a,a+m);
	if(ku())
	 cout<<ans<<endl;
	else
	 cout<<"orz"<<endl;
    return 0;
}
