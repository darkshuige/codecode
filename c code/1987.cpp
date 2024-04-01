#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		for(int i=0;i<t;i++)
		{
			long long n;
			cin>>n;
			cout<<n*(n+1)/2<<endl;
		}
	}
	return 0;
}
