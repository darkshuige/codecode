#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			int x,y,z,a;
			cin>>x>>y>>z;
			if(y==0)
			{
				cout<<0<<endl;
				continue;
			}
			if((y*z)%x==0)
			 a=(y*z)/x+1;
			else
			 a=ceil((double)(y*z)/(double)(x));
			cout<<a<<endl;
		}	
	}
	return 0;
}
