#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
using namespace std;
const int maxn=100005;
struct node
{
	int x,y;
}a[maxn];
int cmp(node a,node b)
{
	return a.y<b.y;
}
priority_queue<int,vector<int>,greater<int> >q;
signed main()
{
	int n,m,k; cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	 cin>>a[i].x>>a[i].y;
	sort(a+1,a+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int r;
		if(i==n)
		 r=m-a[i].y+1;
		else
		 r=a[i+1].y-a[i].y;
		q.push(a[i].x);
		while(q.size()>k) q.pop();
		if(q.size()==k)
		 ans+=q.top()*r;
	}
	cout<<ans<<endl;
	return 0;
}
