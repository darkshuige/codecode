#include<bits/stdc++.h>
using namespace std;
int rn(int y)
{
	if((y%4==0 && y%100!=0) || (y%400==0))
	 return 1;
	else
	 return 0;
}
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			int y,m,d;
			scanf("%d-%d-%d",&y,&m,&d);
			int y1=y+17,m1=m,d1=d;	
			if(m==2 && d==29)
			{
				cout<<-1<<endl;
				continue;
			}
			else
			{
				int count=0;
				if(m>2)
				{
					for(int k=y+1;k<=y+18;k++)
					{
						if(rn(k))
						 count+=366;
						else
						 count+=365;
					}	
				}
				else
				{
					for(int k=y;k<=y+17;k++)
					{
						if(rn(k))
						 count+=366;
						else
						 count+=365;
					}
				}
				cout<<count<<endl;
			}
		}
	}
	return 0;
}
