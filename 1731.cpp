#include<bits/stdc++.h>
using namespace std;
int main()
{
	double r,x1,x2,y1,y2;
	while(cin>>r>>x1>>y1>>x2>>y2)
	{
		if(x1==x2 && y1==y2)
		{
			cout<<0<<endl;
			continue;		
		}
		double l=r*2;
		double d=sqrt((y1-y2)*(y1-y2)+(x1-x2)*(x1-x2));
		int ans;
		if(d/l==(int)(d/l))
		{
			ans=d/l;
		}
		else
		{
			ans=d/l+1;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
