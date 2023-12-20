#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long a,b;
		long long suma=0,sumb=0;
		cin>>a>>b;
		long long a1=a,b1=b;
		while(a1)
		{
			suma=suma+a1%10;
			a1/=10;
		}
		while(b1)
		{
			sumb=sumb+b1%10;
			b1/=10;
		}
		if(a%sumb==0 && a>=sumb && b%suma!=0)
		{
			cout<<"A"<<endl;
		}
		else if(b%suma==0 && b>=suma && a%sumb!=0)
		{
			cout<<"B"<<endl;
		}
		else
		{
			if(a>b)
			 cout<<"A"<<endl;
			else
			 cout<<"B"<<endl;
		}
	}
	return 0;
} 
