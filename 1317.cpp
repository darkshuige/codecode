#include<bits/stdc++.h>
using namespace std;
int f(int a)
{
	int i;
	int sum=0;
	for(i=1;i<=a/2+1;i++)
	{
		if(a%i==0)
		 sum+=i;
	}
	return sum;
}
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int a,b;
		cin>>a>>b;
		int sum1=0,sum2=0;
		int j;
		sum1=f(a);
		sum2=f(b);
		if(sum1==b && sum2==a)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
}
