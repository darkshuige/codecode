#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int k=6,sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=k;
			k=k*10+6;
		}
		cout<<sum<<endl;
	}
	return 0;
}
