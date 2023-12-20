#include<iostream>
#include<stdio.h>
using namespace std;
int pd(int a,int b)
{
	int op[20]={0};
	int i=0;
	while(a)
	{
		op[a%10]++;
		a/=10;
		i++;
	}
	if(i==4)
	 op[0]++;
	i=0;
	while(b)
	{
		op[b%10]++;
		b/=10;
		i++;
	}
	if(i==4)
	 op[0]++;
	for(i=0;i<=9;i++)
	{
		if(op[i]>1)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n>=1 && n<=80)
		{
			int a,b,flag=0;
			for(b=1234;b<=98765;b++)
			{
				a=b*n;
				if(a<=98765)
				{
					if(pd(a,b))
					{
						printf("%05d/%05d=%d\n",a,b,n);
						flag=1;
					}
				}
				else
				{
					break;
				}
			}
			if(flag==0)
			 cout<<"-1"<<endl;	
		}
		else
		 cout<<"-1"<<endl;
	}
	return 0;
}
