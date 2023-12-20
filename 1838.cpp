#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char a[]={'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		 cout<<a[j];
		cout<<endl;
		for(int j=26;j>=2;j--)
		 a[j]=a[j-1];
		a[1]=(char)(a[2]+1);
	}
	return 0;
} 
