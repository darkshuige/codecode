#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		int sum=0;
		sum+=a;
		sum+=c;
		sum-=(c-d);
		cout<<sum<<endl;
	}
	return 0;
} 
