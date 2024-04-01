#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int sum=1;
		while(n!=1)
		{
			sum+=1;
			sum*=2;
			n--;
		}
		cout<<sum<<endl;
	}
	return 0;
}
