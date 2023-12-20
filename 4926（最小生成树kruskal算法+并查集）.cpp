#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int n,f[maxn],m,c,sum;
struct edge
{
	int u,v,w;
}e[maxn];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]==x)
	 return x;
	else
	 return x=find(f[x]);
}
void init()
{
	for(int i=1;i<=n;i++)
	 f[i]=i;
}
int add(int x,int y)
{
	int rx=find(x),ry=find(y);
	if(rx==ry)
	 return 0;
	else
	{
		f[ry]=rx;
		return 1;
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		 break;
		for(int i=1;i<=n*(n-1)/2;i++)
		 scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		sort(e+1,e+1+n*(n-1)/2,cmp);
		init();
		c=sum=0;
		for(int i=1;i<=n*(n-1)/2;i++)
		{
			if(add(e[i].u,e[i].v))
			{
				c++;
				sum+=e[i].w;
			}
			if(c==n-1)
			 break;
		}
		printf("%d\n",sum);
	}
	return 0;
}
