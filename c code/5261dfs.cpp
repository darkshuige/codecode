#include<bits/stdc++.h>
using namespace std;
int s[51][51],n,m,x,y,t,note;
int flag[51];
void dfs(int w)
{
	flag[w]=1;
	if(w==n)
	{
		note=1;
		return ;
	}
	else
	{
		for(int i=1;i<51;i++)
		{
			if(flag[i]==0 && s[w][i]==1)
			{
				flag[i]=1;
				dfs(i);
			}
		}
	}
	return ;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(s,0,sizeof(s));
	    memset(flag,0,sizeof(flag));
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			s[x][y]=1;
		}
		note=0;
		dfs(1);
		if(note)
		 printf("Yes\n");
		else
		 printf("No\n");
	}
} 
