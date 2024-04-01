#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	long long ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ans+=(i+m)/5-i/5;
	}
	cout<<ans<<endl;
	return 0;
}
