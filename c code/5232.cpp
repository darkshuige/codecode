#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		if(a>b)
		 cout<<1;
		else if(a<b)
		 cout<<-1;
		else
		 cout<<0;
		cout<<" ";
		cout<<a+b<<endl;
	}
	return 0;
} 
