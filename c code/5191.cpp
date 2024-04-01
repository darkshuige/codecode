#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a==0 && b==0 && c==0)
		 break;
		cout<<c/(2-((a+b)/a))<<endl;
	}
	return 0;	
} 
