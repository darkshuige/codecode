#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long maxn=INT_MIN;
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			long long a;
			cin>>a;
			if(a>maxn)
			 maxn=a;
		}
		cout<<maxn<<endl;
	}
	return 0;
}
