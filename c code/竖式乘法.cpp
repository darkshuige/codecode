#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int sum1=0,sum2=0;
		for(int i=0;i<a.size();i++)
		 sum1=sum1*10+(a[i]-48);
		for(int i=0;i<b.size();i++)
		 sum2=sum2+(b[i]-48);
		cout<<sum1*sum2<<endl;
	}
	return 0;
}
