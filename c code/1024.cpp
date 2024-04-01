#include<iostream>
using namespace std;
const double PI=3.1415;
int main()
{
	double a,b,c,d;
	double s1,s2,s3;
	double max;
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b>>c>>d;
		s1=a*a;
		s2=b*c;
		s3=d*d*PI;
		max=s1>s2?s1>s3?s1:s3:s2>s3?s2:s3;
		if(max==s1)
		 cout<<"Square"<<endl;
		else if(max==s2)
		 cout<<"Rectangle"<<endl;
		else if(max==s3)
		 cout<<"Circle"<<endl;
	}
	return 0;
}
