#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int fa[maxn],id[maxn],vis[maxn];
int find(int x)
{
	return fa[x]==-1?x:fa[x]=find(fa[x]);
}
int main()
{
	int n,m,ca=0;
	while(cin>>n>>m)
	{
		if(n==0 && m==0) 
		 break;
		for(int i=0;i<n;i++) 
		 id[i]=i;
		memset(fa,-1,sizeof fa);
		int t=n;
		for(int i=0;i<m;i++)
		{
			char ch;
			ch=getchar();
			while(ch!='M'&&ch!='S') 
			 ch=getchar();
			int x,y,z;
			if(ch=='M')
			{
				cin>>x>>y;
				x=id[x],y=id[y];
				int xx=find(x);
				int yy=find(y);
				if(xx!=yy)
				{
					fa[xx]=yy;
				}
			}
			else
			{
				cin>>z;
				id[z]=t++;
			}
		}
		int ans=0;
		memset(vis,-1,sizeof vis);
		for(int i=0;i<n;i++)
		{
			int x=find(id[i]);
			if(vis[x]==-1)
			{
				vis[x]=1;ans++;
			}
		}
		printf("Case #%d: %d\n",++ca,ans);
	}
	return 0;
} 
