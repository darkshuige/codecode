#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,p;
	while(cin>>n>>m>>p)
	{
		char a[105][105]={0};
		int x=-1,y=-1;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			for(int j=0;j<m;j++)
			 if(a[i][j]=='#')
			  x=i,y=j;
		}
		int posx=x,posy=y;
		char op;
		for(int i=0;i<p;i++)
		{
			cin>>op;
			if(op=='L' && y-1>=0 && a[x][y-1]!='*')
			{
				 y--;	
			}
			else if(op=='R' && y+1<m && a[x][y+1]!='*')
			{
				 y++;
			}
			else if(op=='U' && x-1>=0 && a[x-1][y]!='*')
			{
				 x--;
			}
			else if(op=='D' && x+1<n && a[x+1][y]!='*')
			{
				 x++;
			}
		}
		if(x!=posx || y!=posy)
		{
			a[x][y]='#';
			a[posx][posy]='.';	
		} 
		for(int i=0;i<n;i++)
		 cout<<a[i]<<endl;
	}
	return 0;
}
