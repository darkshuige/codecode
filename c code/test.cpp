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
	cout<<(1 & 7);
}