#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
struct node
{
	int a,b;
}aa[maxn];
int sum[maxn];
int cmp(node a,node b)
{
	return a.a<b.a;
}
signed main() 
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		 cin>>aa[i].a>>aa[i].b;
		sort(aa,aa+n,cmp);
		memset(sum,0,sizeof sum);
		sum[0]=aa[0].b;
		for(int i=1;i<n;i++)
		 sum[i]=sum[i-1]+aa[i].b;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(m+sum[i]>=aa[i].a)
			 ans=max(ans,m+sum[i]);
		}
		cout<<max(ans,m)<<endl;
	}
    return 0;
}

