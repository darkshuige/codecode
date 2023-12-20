#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
void swap(int &x,int &y)
{
	int t;
	t=x;
	x=y;
	y=t;
}
int main()
{
	int a,temp,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a>b)
		 swap(a,b);
		temp=((1.0+sqrt(5.0))/2*(b-a));
		if(a==temp)
		 cout<<"0"<<endl;
		else
		 cout<<"1"<<endl;
	}
	return 0;
 
} 
