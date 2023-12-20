#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int a1,a2,a3,a4,a5,a6,b1,b2,b3,b4,b5,b6;
	while(scanf("%d %d %d %d %d %d %d %d %d %d %d %d",&a1,&b1,&a2,&b2,&a3,&b3,&a4,&b4,&a5,&b5,&a6,&b6)!=EOF)
	{
		int sum=0;
		if(a1 && b1)
		{
			if(a1>=2)
			{
				sum=sum+(a1-1)*20;
			}
			sum+=b1;
		}
		if(a2 && b2)
		{
			if(a2>=2)
			{
				sum=sum+(a2-1)*20;
			}
			sum+=b2;
		}
		if(a3 && b3)
		{
			if(a3>=2)
			{
				sum=sum+(a3-1)*20;
			}
			sum+=b3;
		}
		if(a4 && b4)
		{
			if(a4>=2)
			{
				sum=sum+(a4-1)*20;
			}
			sum+=b4;
		}
		if(a5 && b5)
		{
			if(a5>=2)
			{
				sum=sum+(a5-1)*20;
			}
			sum+=b5;
		}
		if(a6 && b6)
		{
			if(a6>=2)
			{
				sum=sum+(a6-1)*20;
			}
			sum+=b6;
		}
		cout<<sum<<endl;
		
	}
	return 0;
}
