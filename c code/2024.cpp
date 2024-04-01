#include<bits/stdc++.h>
using namespace std;
struct gift
{
	int a,b,d;
};
bool cmp(const gift &x,const gift &y)
{
	if(x.d>0 && y.d<0) 
	 return true;
	else if(x.d<0 && y.d>0) 
	 return false;
	else 
	 return x.a<y.a;
}
gift g[1001];
int main(void)
{
	int ncases;
	scanf("%d",&ncases);
	while(ncases--)
	{
		int n,vbeg;
		scanf("%d %d",&n,&vbeg);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&g[i].a,&g[i].b);
			g[i].d=g[i].b-g[i].a;
		}
		sort(g,g+n,cmp);
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			if(vbeg<g[i].a) 
			{
				flag=false;
				break;
			}
			vbeg+=g[i].d;
		}
		if(flag)
		 printf("yes\n");
		else
		 printf("no\n");
	}
	return 0;
}
