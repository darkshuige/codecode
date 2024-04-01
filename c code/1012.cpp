#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int ss(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		 return 0;
	}
	return 1;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(ss(n) && n>=2)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
