#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==0)
		{
			if(b==0 && c==0)
			 printf("NO\n");
			else if(b==0 && c)
			 printf("YES\n");
			else if(b && c%b==0)
			 printf("YES\n");
			else
			 printf("NO\n");
		}
		else
		{
			int dt=b*b-4*a*c;
			if(dt>=0)
			{
				double res1=(-b+sqrt(dt))/(2*a);	
				double res2=(-b-sqrt(dt))/(2*a);
				if(res1-(int)res1==0 && res2-(int)res2==0)
				 printf("YES\n");
				else
			 	 printf("NO\n");
			}
			else
			 printf("YES\n");
		}	
	}
	return 0;
} 
