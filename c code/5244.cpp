#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x,y;
	while(cin>>x>>y)
	{
		if(y>=5)
		 printf("%.2f\n",0.5*x*y);
		else
		 printf("%.2f\n",x*y);
	}
	return 0;
}
