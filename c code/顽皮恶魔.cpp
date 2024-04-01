#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int x[]={-1,-1,-1,0,0,1,1,1};
int y[]={-1,0,1,-1,1,-1,0,1};
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int n,m;
		cin>>n>>m;
		int j,k;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=m;k++)
			{
				cin>>a[j][k];
			}
		}
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=m;k++)
			{
				if(a[j][k]=='*')
				{
					for(int l=0;l<8;l++)
					{
						if(a[j+x[l]][k+y[l]]!='*')
						 a[j+x[l]][k+y[l]]='Z';
					}
				}
			}
		}
		int count=0;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=m;k++)
			{
				if(a[j][k]=='P')
				 count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
