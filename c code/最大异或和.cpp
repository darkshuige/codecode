#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		int a0=0,a1=0,b0=0,b1=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='0')
			 a0++;
			else
			 a1++;
			if(b[i]=='0')
			 b0++;
			else
			 b1++;
		}
		string ans="";
		if(a1+b1<=n)
		{
			int i;
			for(i=0;i<a1+b1;i++)
			 ans+="1";
			for(i=a1+b1;i<n;i++)
			 ans+="0";
		}
		else
		{
			int i;
			for(i=0;i<a0+b0;i++)
			 ans+="1";
			for(i=a0+b0;i<n;i++)
			 ans+="0";
		}
		cout<<ans<<endl;
	} 
	return 0;
}
