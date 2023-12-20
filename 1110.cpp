#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int sum=0,con=1;
		if(n==1)
		{
			cout<<"0"<<endl;
		}
		else if(n==2)
		{
			cout<<"1"<<endl;
		}
		else
		{
			for(int i=1;i<n;i++)
			{
				sum+=con;
				if(i%3==0)
				 con++;
			}
			cout<<sum<<endl; 
		}
		
	}
	return 0;
}
