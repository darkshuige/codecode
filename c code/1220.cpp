#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int maxn=INT_MIN;
		int n,a;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a;
			maxn=max(maxn,a);
		}
		cout<<maxn<<endl;
	}
	return 0;
}
