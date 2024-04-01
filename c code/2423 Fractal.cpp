#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
char mp[731][731];
int ans[731][731];
void print(int n,int x,int y)
{
	if(n==1)
	{
		mp[x][y]='X';
		return ;
	}
	int m=pow(3,n-2);
	print(n-1,x,y);
	print(n-1,x,y+2*m);
	print(n-1,x+m,y+m);
	print(n-1,x+2*m,y);
	print(n-1,x+2*m,y+2*m);
}
signed main()
{
	jiasu;
	int n;
	while(cin>>n)
	{
		memset(ans,0,sizeof ans);
		if(n==-1)
		 break;
		int m=pow(3,n-1);
		for(int i=1;i<=m;i++)
		 for(int j=1;j<=m;j++)
		  mp[i][j]=' ';
		print(n,1,1);
		for(int i=1;i<=m;i++)
		{
			for(int j=m;j>=1;j--)
			 if(mp[i][j]==' ')
			  ans[i][j]=1;
			 else
			  break;
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			 if(ans[i][j]!=1)
			  cout<<mp[i][j];
			 else
			  break;
			cout<<endl;
		}
		cout<<'-'<<endl;
	}
	return 0;
}
 
