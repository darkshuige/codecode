#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		if(m==0)
		{
			cout<<0<<" "<<0<<endl;
			continue;
		}
		else if(m==n)
		{
			cout<<m<<" "<<m<<endl;
			continue;
		}
		cout<<m<<" ";
		if(n-m>=m-1)
		 cout<<1<<endl;
		else
		{
			if(m%(n-m+1)==0)
			{
				cout<<m/(n-m+1)<<endl;
			}
			else
			{
				cout<<m/(n-m+1)+1<<endl;
			}
		}
		 
	}
	return 0;
}
