#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int count=0;
		while(n)
		{
			n/=2;
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
