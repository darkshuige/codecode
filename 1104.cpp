#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int quickmod(int a,int b,int c)
{
	int ans=1;
	while(b)
	{
		if(b%2==1)
		{
			ans=(ans*a)%c;
		}
		b/=2;
		a=(a*a)%c;
	}
	return ans;
}
int main()
{
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		if(a==0 && b==0 && c==0)
		 return 0;
		if(c==1)
		{
			cout<<"0"<<endl;
		}
		else 
		 cout<<quickmod(a,b,c)<<endl;
	}
	return 0;
}
