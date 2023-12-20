#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int y,k,n,x;
	while(scanf("%d %d %d",&y,&k,&n)!=EOF)
	{
		int count=0;
		for(x=n-y;x>0;x--)
		{
			if((x+y)%k==0)
			{
				if(count!=0)
				{
					cout<<" ";
				}
				cout<<x;
				count++;
			}
		}
		if(count==0)
		 cout<<"-1"<<endl;
		else
		 cout<<endl;
	}
	return 0;
}
