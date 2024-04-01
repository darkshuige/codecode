#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,q;
	cin>>q;
	for(i=0;i<q;i++)
	{
		double p,x;
		int t;
		cin>>x>>t;
		p=x/sqrt((t+1)*(x*x)+1);
		cout<<p<<endl;
	}
	return 0;
}
