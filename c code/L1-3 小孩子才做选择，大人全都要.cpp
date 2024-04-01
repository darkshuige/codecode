#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a>0 && b>0)
	{
		cout<<max(a,b)<<" "<<a+b<<endl;
		cout<<"^_^"<<endl;
	}
	else if((a<0 && b>0) || (b<0 && a>0))
	{
		if(a+b>0)
		{
			cout<<max(a,b)<<" "<<a+b<<endl;	
		}
		else
		{
			cout<<max(a,b)<<" "<<"0"<<endl;
		}
		cout<<"T_T"<<endl;
	}
	else if(a<0 && b<0)
	{
		cout<<"0 0"<<endl;
		cout<<"-_-"<<endl;
	}
	return 0;
}
