#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[105][105];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin>>a[i][j];
		}
	}
	int x,y,k;
	char s;
	cin>>x>>y>>s>>k;
	int posx=x,posy=y;
	for(int t=0;t<k;t++)// 1ÓÒ×ª  0×ó×ª
	{
		if(a[posx][posy]==1)
		{
			a[posx][posy]=0;
			if(s=='U')
			{
				s='R';
				posy++;
			}
			else if(s=='D')
			{
				s='L';
				posy--;
			}
			else if(s=='L')
			{
				s='U';
				posx--;
			}
			else if(s=='R')
			{
				s='D';
				posx++;
			}
		}
		else
		{
			a[posx][posy]=1;
			if(s=='U')
			{
				s='L';
				posy--;
			}
			else if(s=='D')
			{
				s='R';
				posy++;
			}
			else if(s=='L')
			{
				s='D';
				posx++;
			}
			else if(s=='R')
			{
				s='U';
				posx--;
			}
		}
	}
	cout<<posx<<" "<<posy<<endl;
    return 0;
}
