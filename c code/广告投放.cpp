#include<iostream>
#include<math.h>
using namespace std;
long long dist(int x1,int x2,int y1,int y2)
{
	return pow(x1-x2,2)+pow(y1-y2,2);
}
struct yingxiong
{
	int k;
	int x;
	int y;
	int hp;
	int r;
	bool g;
}a[2005];
int main()
{
	int n,i,count1=0,count2=0,c;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i].k>>a[i].x>>a[i].y>>a[i].hp;
		if(a[i].k==2)
		 cin>>a[i].r;
	}	
	for(i=0;i<n;i++)
	{
		if(a[i].k==2)
		{
			int dis=1e9+7;
			int h=-1;
			int j;
			for(j=0;j<i;j++)
			{
				if(a[j].hp<=0 || a[j].k==2)
				 continue;
				long long s=dist(a[i].x,a[j].y,a[i].x,a[j].y);
				if(s<dis)
				{
					dis=s;
					h=j;
				}
			}
			if(h!=-1)
			{
				for(j=0;j<i;j++)
				{
					if(a[j].hp<=0 || a[j].k==2)
				 	 continue;
				 	dis=dist(a[h].x,a[j].y,a[h].x,a[j].y);
				 	if(dis<=a[i].r*a[i].r)
				 	{
				 		a[j].hp-=3*a[i].hp;
						if(a[j].hp<=0)
						 a[j].g=1;
						else
						 a[i].g=1;					
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i].g==1)
		 cout<<"NO"<<endl;
		else
		 cout<<"YES"<<endl;
	}
	return 0;
}
