#include<iostream>
#include<stdio.h>
using namespace std;
int rn(int a)
{
	if(a%400==0)
	 return 1;
	if(a%4==0 && a%100!=0)
	 return 1;
	return 0;
}
int main()
{
	int t,i,p1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int p2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int sum=0;
		int y1,y2,m1,m2,d1,d2;
		scanf("%d %d %d %d %d %d",&y1,&m1,&d1,&y2,&m2,&d2);
		while(y1!=y2 || m1!=m2 || d1!=d2)
		{
			if((y1/10==202) || (y1%1000==202) || (y1%10==2 && m1==2) || (m1==2 && d1==2) ||(m1==12 && d1==2))
			{
				sum++;
			}
			d1++;
			if(rn(y1))
			{
				if(d1==p2[m1]+1)
				{
					m1++;
					d1=1;
				}
				if(m1==13)
				{
					y1++;
					m1=1;
				}	
			}
			else
			{
				if(d1==p1[m1]+1)
				{
					m1++;
					d1=1;
				}
				if(m1==13)
				{
					y1++;
					m1=1;
				}	
			}
			
		}
		if((y2/10==202) || (y2%1000==202) || (y2%10==2 && m2==2) || (m2==2 && d2==2) || (m2==12 && d2==2))
		 sum++;
		printf("%d\n",sum);
	}
	return 0;
}
