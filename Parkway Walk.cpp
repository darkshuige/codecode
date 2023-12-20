#include<iostream>
using namespace std;
int main()
{
	int i,t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int m,n,a;
		cin>>n>>m;
		int j,sum=0;
		for(j=0;j<n;j++)
		{
			cin>>a;
			sum+=a;
		}
		if(sum<=m)
		 cout<<"0"<<endl;
		else
		 cout<<sum-m<<endl;
	}
	return 0;
} 
