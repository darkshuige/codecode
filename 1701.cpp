#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		int sum=0;
		for(int i=1;i<=t;i++)
		{
			int a;
			cin>>a;
			sum+=a%i;
		}
		cout<<sum<<endl;
	}
	return 0;
}
