#include<iostream>
using namespace std;
int main()
{
	int n,i,a;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(a%2==0)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
} 
