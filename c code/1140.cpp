#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct wssb
{
	int xs,fz;
	double a;
}op[5];
bool cmp(struct wssb op1,struct wssb op2)
{
	if(op1.a!=op2.a)
	 return op1.a<op2.a;
	if(op1.xs==op2.xs)
	{
		return op1.fz<op2.fz;
	}
	else
	 return op1.xs<op2.xs;
}
int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{
		for(i=0;i<5;i++)
		{
			scanf("%d:%d",&op[i].xs,&op[i].fz);
			op[i].a=abs(op[i].fz*6-((op[i].xs%12)*30+op[i].fz/2.0));
			if(op[i].a>180)
			{
				op[i].a=360-op[i].a;
			}
		}
		sort(op,op+5,cmp);
		for(i=0;i<5;i++)
		{
			if(i!=0)
			 cout<<" ";
			printf("%02d:%02d",op[i].xs,op[i].fz);	
			
		}
		 cout<<endl;
	}
	return 0;
}
