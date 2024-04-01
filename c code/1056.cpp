#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int n,mod_old,mod_even,j;
		cin>>n>>mod_old>>mod_even;
		for(j=0;j<n;j++)
		{
			int k,sum=0,sum_old=0,sum_even=0,value;
			string s;
			cin>>s;
			for(k=0;k<s.size();k++)
			{
				sum=sum+(int)(s[k]);
				if(k%2==0)
				{
					sum_old+=(int)(s[k]);
				}
				else
				{
					sum_even+=(int)(s[k]);
				}
			}
			value=sum_old%mod_old + sum_even%mod_even;
			cout<<"("<<value<<","<<sum<<")"<<endl;
		}
	}
	return 0;
}
