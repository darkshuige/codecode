#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char a[105][105];
	for(int i=0;i<n;i++)
	 cin>>a[i];
	char t=a[0][0];
	for(int i=0;i<n-1;i++)
	{
		a[i][0]=a[i+1][0];
	}
	for(int i=0;i<n-1;i++)
	{
		a[n-1][i]=a[n-1][i+1];
	}
	for(int i=n-1;i>0;i--)
	{
		a[i][n-1]=a[i-1][n-1];
	}
	for(int i=n-1;i>1;i--)
	{
		a[0][i]=a[0][i-1];
	}
	a[0][1]=t;
	for(int i=0;i<n;i++)
	 cout<<a[i]<<endl;
	return 0;	
} 
