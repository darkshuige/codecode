#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int sum;
		cin>>sum;
		int a;
		char op;
		while(1)
		{
			cin>>op;
			if(op=='+')
			{
				cin>>a;
				sum+=a;
			}
			else if(op=='-')
			{
				cin>>a;
				sum-=a;
			}
			else if(op=='*')
			{
				cin>>a;
				sum*=a;
			}
			else if(op=='/')
			{
				cin>>a;
				sum/=a;
			}
			else if(op=='=')
			{
				break;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
