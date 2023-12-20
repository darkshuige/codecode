#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int maxn=100005;
int a[maxn];
struct node
{
	int l,r,w;
};
int cmp(node a,node b)
{
	if(a.w!=b.w)
	 return a.w>b.w;
	else
	 return a.l<b.l;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		node tr[maxn];
		int n,cnt=0,l=1,r=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		for(int i=2;i<=n;i++)
		{
			if(a[i]>=a[i-1])
			 r=i;
			else
			{
				tr[++cnt]={l,r,a[r]-a[l]};
				l=i,r=i;
			}
		}
		tr[++cnt]={l,r,a[r]-a[l]};
		sort(tr+1,tr+cnt+1,cmp);
		cout<<tr[1].l<<" "<<tr[1].r<<" ";
		for(int i=2;i<=cnt;i++)
		{
			if(tr[i].w==tr[i-1].w)
			 cout<<tr[i].l<<" "<<tr[i].r<<" ";
			else
			 break;
		}
		cout<<endl;
	}
	return 0;
} 
