#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=10;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	int ans=0;
	int p=0;
	for(int i=0;i<n;i++)
	{
		char op=a[i]+p;
		if(op!=b[i])
		{
			if(op<b[i])
			 p+=(b[i]-op);
			else
			 p+=26-(op-b[i]);
			ans++;	
			p%=26;
		}
	}
	cout<<ans<<endl;
	return 0;
} 

