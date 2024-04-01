#include<bits/stdc++.h>
using namespace std;
bool rn(int year)
{
	if((year%4==0 && year%100!=0) || year%400==0)
	 return 1;
	else 
	 return 0;
}
int mon1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int mon2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int year,mon,day;
	int year3=2013,mon3=3,day3=9;
	while(scanf("%d-%d-%d",&year,&mon,&day)!=EOF)
	{
		int sum=0;
		while(year!=year3 || mon!=mon3 || day!=day3)
		{
			sum++;
			if(rn(year))
			{
				day++;
				if(day>mon2[mon])
				{
					day-=mon2[mon];
					mon++;
				}
				if(mon>12)
				{
					mon-=12;
					year++;
				}
			}
			else
			{
				day++;
				if(day>mon1[mon])
				{
					day-=mon1[mon];
					mon++;
				}
				if(mon>12)
				{
					mon-=12;
					year++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
