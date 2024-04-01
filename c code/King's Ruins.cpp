#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=50005;
struct node
{
	int a,b,c,d,e;
	int value;
}op[maxn];
int check(node a,node b)
{
	if(a.a<=b.a && a.b<=b.b && a.c<=b.c && a.d<=b.d && a.e<=b.e)
	 return 1;
	else 
	 return 0;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(op,0,sizeof(node)*maxn);
		int dp[maxn]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>op[i].a>>op[i].b>>op[i].c>>op[i].d>>op[i].e>>op[i].value;
			dp[i]=op[i].value;
			for(int j=1;j<=i-1;j++)
			{
				if(check(op[j],op[i]))
				{
					dp[i]=max(dp[i],dp[j]+op[i].value);
				}
			}
		}
		for(int i=1;i<=n;i++)
		 cout<<dp[i]<<endl;
	}
	return 0;
}
