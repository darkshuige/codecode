#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20005;
struct node
{
	int l,r;
}a[maxn];
int cmp(node a,node b)
{
	if(a.l!=b.l)
	 return a.l<b.l;
	else
	 return a.r<b.r;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i].l>>a[i].r;
	sort(a,a+n,cmp);
	int sum=0;
	int st=a[0].l,ed=a[0].r;
	sum+=ed-st;
	for(int i=1;i<n;i++)
	{
		if(a[i].r<ed);
		else if(a[i].l<=ed && a[i].r>ed)
		{
			st=ed;
			ed=a[i].r;
			sum+=ed-st;
		}
		else if(a[i].l>ed)
		{
			st=a[i].l;
			ed=a[i].r;
			sum+=ed-st;
		}
	}
	cout<<sum<<endl;
	return 0;
}
