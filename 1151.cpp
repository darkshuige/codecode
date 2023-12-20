#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n%2==0)
		{
			while(n)
			{
				cout<<"1";
				n-=2;
			}
			cout<<endl;
		}
		else
		{
			cout<<"7";
			n-=3;
			while(n)
			{
				cout<<"1";
				n-=2;
			}
			cout<<endl;
		}
	}
	return 0;
}
