#include<iostream>
using namespace std;
int main()
{
	int i,n,sum=0,b;
	cin>>n;
	while(n!=0)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>b;
			sum+=b;
		}
		cout<<sum<<endl;
		cin>>n;
	}
	return 0;
} 
