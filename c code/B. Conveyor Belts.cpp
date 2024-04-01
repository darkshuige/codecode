#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int find(int x,int y,int n)
{
	int k,op;
	if(x<=n/2 && y<=n/2)
	{
		k=min(x,y);
	}
	else if(x>=n/2 && y<=n/2)
	{
		x=x-n/2;
		y=n/2-y+1;
		op=max(x,y);
		k=n/2-op+1;
	}
	else if(x<=n/2 && y>=n/2)
	{
		y=y-n/2;
		y=n/2-y+1;
		k=min(x,y);
	}
	else if(x>=n/2 && y>=n/2)
	{
		op=max(x-n/2,y-n/2);
		k=n/2-op+1;
	}
	return k;
}
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int n,x1,x2,y1,y2;
		cin>>n>>x1>>y1>>x2>>y2;
		int a1,a2;
		a1=find(x1,y1,n);
		a2=find(x2,y2,n);
		cout<<abs(a1-a2)<<endl;
	}
	return 0;
}
