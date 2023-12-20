#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[2][3],b[3][2],c[2][2];
	while(cin>>a[0][0]>>a[0][1]>>a[0][2]>>a[1][0]>>a[1][1]>>a[1][2])
	{
		int n=2,m=3,p=3,q=2;
		for(int i=0;i<p;i++)
		{
			for(int j=0;j<q;j++)
			 cin>>b[i][j];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<q;j++)
			{
				c[i][j]=0;
				for(int k=0;k<m;k++)
				 c[i][j]+=a[i][k]*b[k][j];	
			}
		}
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(j!=0)
				 cout<<" ";
				cout<<c[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
} 
