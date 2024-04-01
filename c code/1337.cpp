#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,r;
	while(cin>>l>>r)
	{
		long long sum1=0,sum2=0;
		for(int i=l;i<=r;i++)
		{
			if(i%2==0)
			{
				sum1+=pow(i,2);
			}
			else
			{
				sum2+=pow(i,3);
			}
		}
		cout<<sum1<<" "<<sum2<<endl;
	}
	return 0;
}
