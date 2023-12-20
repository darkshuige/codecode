#include<iostream>
using namespace std;
int main()
{
	long long a,n,op;
	while(cin>>a>>n)
	{
		long long sum=0;
		op=a;
		int i;
		for(i=0;i<n;i++)
		{
			
			sum+=a;
			a=a*10+op;	
		}
		cout<<sum<<endl;	
	}
	
	return 0;
}
