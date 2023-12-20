#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn];
int h[maxn];
int c[maxn]={0};
int v[maxn];
signed main()
{
	jiasu;
	int n,q,k;
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=c[i-1]+a[i];
	}
	cin>>h[1];
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		cin>>h[i];
		if(h[i]>h[i-1])
		 v[cnt++]=i;
	}
	for(int i=0;i<q;i++)
	{
		int x;
		cin>>x;
		int pos2=x;
		int pos;
		while(1)
		{
			pos=x-k+1;
			if(pos<1)
			{
				pos=1;
				break;
			}
			int p=upper_bound(v,v+cnt,pos)-v;
			if(v[p]<=x && p<cnt && p>=0)
			{
				x=v[p]-1;
			}
			else
			{
				break;
			}	
		}
		cout<<c[pos2]-c[pos-1]<<endl;
	}
	return 0;
} 
