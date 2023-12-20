#include<iostream>
#include<math.h>
const int eps=1e-8;
using namespace std;
int main()
{
	double x,y;
	int a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		x=b*log(a);
		y=d*log(c);
		if(fabs(x-y)<=1e-8)
		 cout<<"="<<endl;
		else if(x>y)
		 cout<<">"<<endl;
		else if(x<y)
		 cout<<"<"<<endl;	
	}
	
	return 0;
}
