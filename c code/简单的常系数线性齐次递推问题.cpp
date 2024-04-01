#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main()
{
	int k,m;
	cin>>k>>m;
	long long c[55]={0},a[1005]={0};
	for(int i=1;i<=k;i++)
	 cin>>c[i];
	for(int i=1;i<=k;i++)
	 cin>>a[i];
	for(int i=k+1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			a[i]+=c[j]*a[i-j];
			a[i]%=mod;
		}
	}
	cout<<a[m]<<endl;
	return 0;
} 
