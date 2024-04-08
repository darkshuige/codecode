#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
struct node
{
	int a,b;
	int cha;
}k[maxn];
int cmp(node a,node b)
{
	if(a.cha!=b.cha)
	 return a.cha<b.cha;
	else
	 return a.b>b.b;
}
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		for(int i=1;i<=n;i++)
		{
			k[i].a=i; cin>>k[i].b;
			k[i].cha=k[i].a-k[i].b;
		}
		sort(k+1,k+1+n,cmp);
		int sum=0;
		int pos=1;
		while(pos<=n-2)
		{
			if(k[pos].cha==k[pos+1].cha)
			{
				if(k[pos].b+k[pos+1].b>=0)
				{
					sum+=k[pos].b+k[pos+1].b;
				els
			}
			else pos++;
		}
		cout<<sum<<endl;
	}
	return 0;
}