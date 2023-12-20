#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a<=c)
		{
			if(b>=c)
			{
				cout<<c<<endl;
			}
			else if(b<c)
			{
				cout<<a+c<<endl;
			}	
		}
		else
		{
			if(a<=d)
			{
				cout<<a<<endl;
			}			
			else if(a>d)
			{
				cout<<a+c<<endl;
			}
		}//c d a b
	}
	return 0;
}
