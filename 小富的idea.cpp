#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
const double EPS = 1e-6;
int f[maxn],n,sum[maxn];
double d[maxn][maxn];
void init()
{
	for(int i=1;i<=n;i++)
	 f[i]=i;
}
int find(int x)
{
	if(x!=f[x])
	 return f[x]=find(f[x]);
	return f[x];
}
struct node
{
	int x,y,v;
}a[maxn];
signed main()
{
	jiasu;
	cin>>n;
	init();
	sum[0]=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].x>>a[i].v;
		for(int j=1;j<i;j++)
		 d[i][j]=d[j][i]=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
	}
	int pos=-1;
	for(int t=1;t<=1000;t++)
	{
		sum[t]=sum[t-1];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int x=find(i),y=find(j);
				if(x!=y)
				{
					int c=(a[i].v+a[j].v)*t;
					if(c-d[i][j]>=EPS)
					{
						f[x]=y;
						sum[t]--;
					}
					if(sum[t]==1)
					{
						pos=t;
						goto end;
					}
				}
				
			}
		}
	}
	end:
	int q;
	cin>>q;
	while(q--)
	{
		int t;
		cin>>t;
		if(pos!=-1 && t>=pos)
		 cout<<1<<endl;
		else
		 cout<<sum[t]<<endl;
	}
	return 0;
}
