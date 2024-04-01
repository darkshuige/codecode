#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int b[1005][1005];
int main()
{
	int n,m;
	cin>>n>>m;
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<n-1;i+=2)
	{
		for(j=0;j<m-1;j+=2)
		{
			b[i/2][j/2]=(int)((a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1])/4);
		}
	}
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<m/2;j++)
		{
			if(j!=0)
			 cout<<" ";
			cout<<b[i][j];
		}
		cout<<endl;
	}
	return 0;
} 
