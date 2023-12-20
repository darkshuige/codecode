#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x,y;
	while(cin>>x>>y)
	{
		if(x==y)
		{
			cout<<"0"<<endl;
			continue;
		}
		int count=0;
		long long w=y-x;
		long long sum=0;
		long long i;
		for(i=1;;i++)
		{
			sum+=i;
			count++;
			if(sum>=w)
			{
				cout<<count<<endl;
				break;
			}
			sum+=i;
			count++;
			if(sum>=w)
			{
				cout<<count<<endl;
				break;
			}
		}
	}
	return 0;
} 
