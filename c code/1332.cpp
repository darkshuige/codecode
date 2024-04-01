#include<bits/stdc++.h>
using namespace std;
int yr1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int yr2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int rn(int y)
{
	if(y%4==0 && y%100!=0)
	 return 1;
	if(y%400==0)
	 return 1;
	return 0;
}
int main()
{
	int year,mon,day;
	while(cin>>year>>mon>>day)
	{
		int n=10000;
		while(n)
		{
			if(rn(year))
			{
				day++;
				n--;
				if(day>yr2[mon])
				{
					mon++;
					day=1;
				}
				if(mon>12)
				{
					year++;
					mon=1;
				}
			}
			else
			{
				day++;
				n--;
				if(day>yr1[mon])
				{
					mon++;
					day=1;
				}
				if(mon>12)
				{
					year++;
					mon=1;
				}
			}
		}
		printf("%d-%d-%d\n",year,mon,day);
	}
	return 0;
}
