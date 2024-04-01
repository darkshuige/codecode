#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
struct node
{
	int w,s;
}a[maxn];
int cmp(node a,node b)
{
	return a.w+a.s<b.w+b.s;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i].w>>a[i].s;
	sort(a,a+n,cmp);
	int maxn=-a[0].s;
	int sum=a[0].w;
	for(int i=1;i<n;i++)
	{
		maxn=max(maxn,sum-a[i].s);
		sum+=a[i].w;
	}
	cout<<maxn<<endl;
	return 0;
}
