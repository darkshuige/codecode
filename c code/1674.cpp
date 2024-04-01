#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x,y,z;
	while(cin>>x>>y>>z)
	{
		int flag=1;
		long long a,b,c;
		if((x+y-2*z)%4==0)
		{
			a=(x+y-2*z)/4+z;
			b=(x+y-2*z)/4;	
		}
		else
		 flag=0;
		if((x-y)%2==0)
		 c=(x-y)/2;
		else
		 flag=0;
		if(a>=0 && b>=0 && c>=0 && flag)
		 cout<<a<<" "<<b<<" "<<c<<endl;
		else 
		 cout<<"wangwangwang"<<endl;
	}
	return 0;
}
