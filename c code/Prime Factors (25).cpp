#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int>mp;
int isp(int n)
{
	if(n<=1) return 0;
	for(int i=2;i<=sqrt(n);i++)
	 if(n%i==0) return 0;
	return 1;
}
signed main()
{
	int n; cin>>n;
	if(n==1 || n==2)
	{
		cout<<n<<"="<<n<<endl;
		return 0;
	}
	else if(isp(n))
	{
		cout<<n<<"="<<n<<endl;
		return 0;
	}
	int m=n;
	for(int k=2;k<=sqrt(n);k++)
	{
		while(isp(k) && n%k==0)
		{
			mp[k]++;
			n/=k;
		}
		if(isp(n))
		{
			mp[n]++;
			break;
		}
		if(n==1) break;
	}
	cout<<m<<"=";
	int cnt=0;
	for(auto k:mp)
	{
		if(cnt!=0) cout<<"*";
		cnt++;
		if(k.second==1)
		 cout<<k.first;
		else
		 cout<<k.first<<"^"<<k.second;
	}
    return 0;
}