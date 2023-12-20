#include<bits/stdc++.h>
using namespace std;
double act(int x1,int y1,int x2,int y2)
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int check(double a,double b,double c)
{
	int op[3];
	op[0]=a;op[1]=b;op[2]=c;
	sort(op,op+3);
	if(op[0]+op[1]>op[2])
	 return 1;
	else
	 return 0;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		pair<double,double>p[120];
		for(int i=0;i<n;i++)
		 scanf("%lf %lf",&p[i].first,&p[i].second);
		double maxn=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int z=j+1;z<n;z++)
				{
					double s=0.5*(p[i].first*p[j].second+p[j].first*p[z].second+p[z].first*p[i].second-(p[z].first*p[j].second+p[j].first*p[i].second+p[i].first*p[z].second));   
					if(s<0) 
					 s=-s;
					if(s>maxn)
					 maxn=s;                 
				}
			}
		}
		int as=(int)maxn;
		printf("%d\n",as);
	}
}
