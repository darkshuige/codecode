#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdio>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
void calc(int n,int id,int &x,int &y)
{
	if(n==1)
	{
		if(id==1)
		 x=1,y=1;
		if(id==2)
		 x=1,y=2;
		if(id==3)
		 x=2,y=2;
		if(id==4)
		 x=2,y=1;
	}
	else
	{
		int _id=(1<<(n-1))*(1<<(n-1));//n-1分级总数 
		if(id<=_id)
		{
			calc(n-1,id-_id,y,x);
		}
		else if(id<=2*_id)
		{
			calc(n-1,id-_id,x,y);
			y+=1<<(n-1);
		}
		else if(id<=3*_id)
		{
			calc(n-1,id-2*_id,x,y);
			x+=1<<(n-1);
			y+=1<<(n-1);
		}
		else
		{
			calc(n-1,id-3*_id,y,x);
			x=(1<<n)+1-x;
			y=(1<<n-1)+1-y;
		}
	}
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,h,o;
		cin>>n>>h>>o;
		int sx,sy,ex,ey;
		calc(n,h,sx,sy);
		calc(n,o,ex,ey);
		printf("%.0f\n",sqrt((sx-ex)*1.0*(sx-ex)+(sy-ey)*(sy-ey)*1.0)*10);
	}
	return 0;
}
