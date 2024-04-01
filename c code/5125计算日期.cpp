#include<bits/stdc++.h>
using namespace std;
int days_of_year(int year)
{
	if((year%4==0 && year%100!=0) || year%400==0)
	 return 366;
	else 
	 return 365;
}
int days_of_month(int mon,int year)
{
	if(mon==2)
	 return days_of_year(year)==366?29:28;
	int d;
	switch(mon)
	{
		case 1:case 3:case 5: case 7:case 8:case 10:case 12:
			d=31;
			break;
		default:
			d=30;
	}
	return d;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int year,mon,day;
		int n;
		cin>>year>>mon>>day>>n;
		n--;
		while(n)
		{
			if(n>=days_of_year(year))
			{
				n-=days_of_year(year);
				year++;
			}
			else if(n>=days_of_month(mon,year))
			{
				n-=days_of_month(mon,day);
				mon++;
			}
			else
			{
				day+=n;
				n=0;
			}
		}
		if(day>days_of_month(mon,year))
		{
			day-=days_of_month(mon,year);
			mon++;
		}
		if(mon>12)
		{
			mon-=12;
			year++;
		}
		printf("%d%02d%02d\n",year,mon,day);
	}
	return 0;
} 
