#include<iostream>
using namespace std;
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int n,j,a,min;
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>a;
			if(j==0)
			 min=a*3;
			else
			{
				if(a%2==0)
				{
					a=a+2;
				}
				else
				{
					a=a+1;
				}
				if(a>min)
				{
					min=a;
				}
			}
		}
		cout<<min<<endl;
	}
	return 0;
}
