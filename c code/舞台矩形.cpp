#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
struct wz
{
	int x;
	int y;
}a[100005];
int main()
{
	int b[100005]={0};
	int n,q,i,d1,d2,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>d1>>d2;
		if(d1==d2)
		{
			cout<<0<<endl;
		}
		else
		{
			if(a[d1].x==a[d2].x)
			{
				cout<<0<<endl;
			}
			else
			{
				int max=-1000000000,min=100000000;
				int x1=a[d1].x,x2=a[d2].x,da,xiao;
//				if(a[d1].x>a[d2].x)
//				{
//					da=a[d1].x;
//					xiao=a[d2].x;
//				}
//				else
//				{
//					da=a[d2].x;
//					xiao=a[d1].x;
//				}
				int l=0;
				for(j=1;j<=n;j++)
				{
					if(((a[j].x<=a[d1].x && a[j].x>=a[d2].x) || (a[j].x>=a[d1].x && a[j].x<=a[d2].x)))
					{
						if(a[j].y>max)
						 max=a[j].y;
						if(a[j].y<min)
						 min=a[j].y;
						b[l]=a[j].x;
					    l++;
					}
				}
				sort(b,b+l);
				cout<<abs(b[0]-b[l-1])*abs(max-min)<<endl;
			}
		}
	}
	return 0;
}
