#include<bits/stdc++.h>
using namespace std;
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
const int maxn=100005;
int f[maxn];
struct node
{
	int x,y,w;
}a[maxn];
int cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]!=x)
	 f[x]=find(f[x]);
	return f[x];
}
signed main()
{
	int n,m,c;
	scanf("%lld%lld%lld",&n,&m,&c);
	for(int i=1;i<=n;i++)
	 f[i]=i;
	for(int i=0;i<m;i++)
	 scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].w);
	sort(a,a+m,cmp);
	int sum=0,k=0;
	vector<int>v;
	for(int i=0;i<m;i++)
	{
		int x=a[i].x,y=a[i].y;
		x=find(x),y=find(y);
		if(x!=y)
		{
			f[y]=x;
			v.push_back(a[i].w);
		}
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		if(sum+v[i]*(++k)>c)
		{
			printf("%lld\n",v[i]);
			return 0;
		}
		sum+=v[i]*k;
	}
	printf("0\n");
	return 0;	
} 
