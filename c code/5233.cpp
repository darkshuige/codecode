#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x1,x2,y1,y2;
	while(cin>>x1>>y1>>x2>>y2)
	{
		double x3=x1,y3=y2,x4=x2,y4=y1;
		double zc=abs(y2-y1)*2+abs(x1-x2)*2,mj=abs(x1-x2)*abs(y1-y2);
		printf("(%.2f,%.2f) (%.2f,%.2f) %.2f %.2f\n",x1,y1,x2,y2,zc,mj);
	}
	return 0;
}
