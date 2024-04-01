#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int a;
		double b;
		cin>>a>>b;
		int red=0;
		double green=0;
		int ex=0;
		while(a)
		{
			red+=a*100;
			if(10000>a*100*(b-1))
			{
				green+=a*100*(b-1);
			}
			else
			{
				green+=10000;
			}
			a=0;
			a+=(int)(red/200);
			ex+=(int)(red/10);
			ex+=(int)(green/10);
			red=0;
			green=0;
		}	
		cout<<ex<<endl;
	}	
	return 0;
}
