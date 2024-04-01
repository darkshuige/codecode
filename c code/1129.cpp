#include<iostream>
#include<cmath>
using namespace std;
const double PI = acos(-1);
const double e = exp(double(1));
int str(int n)
{
    return floor(log10(sqrt(2*PI*n))+n*log10(n/e))+1;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n<=3)
		 cout<<"1"<<endl;
		else
		 cout<<str(n)<<endl;
	}
	return 0;
}
