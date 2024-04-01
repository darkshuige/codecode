#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long n,m;
		cin>>n>>m;
		if(n<=4)
		 cout<<n*m<<endl;
		else if(n==5)
		 cout<<4*m<<endl;
		else
		{
			long long sum=0;
			sum+=4*m;
			n-=5;
			sum+=(n/4)*(m*3)+(n%4)*m;
			cout<<sum<<endl;
		}
	}
	return 0;
}
