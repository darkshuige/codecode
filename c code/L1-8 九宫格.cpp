#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=20;
int a[maxn][maxn];
map<int,int>mp;
map<int,int>hang;
map<int,int>lie;
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		for(int i=1;i<=9;i++)
		 for(int j=1;j<=9;j++)
		  cin>>a[i][j];
		int flag=1;
		for(int i=1;i<=7;i+=3)
		{
			for(int j=1;j<=7;j+=3)
			{
				mp.clear();
				for(int x=i;x<=i+2;x++)
				{
					for(int y=j;y<=j+2;y++)
					{
						if(mp[a[x][y]]==0 && a[x][y]<=9 && a[x][y]>=1)
						 mp[a[x][y]]++;
						else
						{
							flag=0;
							break;
						}
					}
				}
			}
		}
		
		for(int i=1;i<=9;i++)
		{
				hang.clear();
			for(int y=1;y<=9;y++)
			{
					if(hang[a[i][y]]==0 && a[i][y]<=9 && a[i][y]>=1)
					 hang[a[i][y]]++;
					else
					{	
						flag=0;
						break;
					}
			}
		}
		
		for(int j=1;j<=9;j++)
		{
			lie.clear();
			for(int x=1;x<=9;x++)
			{
					if(lie[a[x][j]]==0 && a[x][j]<=9 && a[x][j]>=1)
					 lie[a[x][j]]++;
					else
					{	
						flag=0;
						break;
					}
			}
		}
		cout<<flag<<endl;
	}
	return 0;
}