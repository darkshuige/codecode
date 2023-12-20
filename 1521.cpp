#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int k=n/2;
		for(int j=1;j<=n;j+=2)
		{
			for(int l=0;l<k;l++)
			 cout<<" ";
			k--;
			for(int l=0;l<j;l++)
			 cout<<'*';
			cout<<endl;
		}
		k=1;
		for(int j=n-2;j>=1;j-=2)
		{
			for(int l=0;l<k;l++)
			 cout<<" ";
			k++;
			for(int l=0;l<j;l++)
			 cout<<'*';
			cout<<endl;
		}
	}
	return 0;
}
