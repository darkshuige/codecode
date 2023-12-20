#include<bits/stdc++.h>
using namespace std;
int f(int a)
{
	if(a<2)
	{
		return 0;
	}
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		if(f(a))
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
} 
