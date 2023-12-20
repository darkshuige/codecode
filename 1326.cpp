#include<bits/stdc++.h>
using namespace std;
int a[35][35];
void init()
{
	a[1][1]=1;
	a[2][1]=1;
	a[2][2]=1;
	int i,j;
	for(i=1;i<35;i++)
	{
		a[i][1]=1;
	}
	for(i=3;i<35;i++)
	{
		for(j=2;j<=i;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
}
int main()
{
	init();
	int n;
	while(cin>>n)
	{
		int i,j;
		for(i=1;i<=n;i++)
		{
			int count=0;
			for(j=1;j<=i;j++)
			{
				cout<<a[i][j]<<" ";

			}
			cout<<endl;			
		}
		cout<<endl;
	}
	return 0;
}
