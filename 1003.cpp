#include<iostream>
using namespace std;
int main()
{
	int t,i,n,sum,j,a;
	cin>>t;
	for(i=0;i<t;i++)
	{
		sum=0;
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>a;
			sum+=a;
		}
		cout<<sum<<endl;

	}
	return 0;
}
