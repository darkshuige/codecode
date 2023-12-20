#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	while(cin>>n)
	{
		if(n>0)
		 cout<<"B*C"<<endl;
		else if(n==0)
		 cout<<"A*B B*C"<<endl;
		else
		 cout<<"A*B"<<endl;
	}
	return 0;	
} 
