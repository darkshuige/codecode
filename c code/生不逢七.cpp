#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=100005;
char s[maxn];
int check(int a)
{
	int flag=1;
	if(a%7==0)
	 return 0;
	while(a)
	{
		if(a%10==7)
		 return 0;
		a/=10;
	}
	return 1;
}
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int n,a,k; cin>>n>>a>>k;
		int sum=0;
		a++;
		for(int j=1;j<=k;j++)
		{
			if(j!=1) cout<<" ";
			if(sum%n==0)
			{
				if(check(a)==0)
				 cout<<"p";
				else
				 cout<<a;
			}
			a+=n;
		}
		cout<<endl;
	}
	return 0;
}

