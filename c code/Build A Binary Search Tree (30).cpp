#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=105;
struct node
{
	int ls,rs;
	int x;
}a[maxn];
int b[maxn];
int pos;
void dfs(int now)
{
	if(a[now].ls!=-1) dfs(a[now].ls);
	a[now].x=b[pos++];
	if(a[now].rs!=-1) dfs(a[now].rs);
}
void bfs(int now)
{
	queue<int>q;
	q.push(now);
	while(!q.empty())
	{
		if(pos!=0)
		 cout<<" ";
		pos++;
		int k=q.front();
		cout<<a[k].x; q.pop();
		if(a[k].ls!=-1) q.push(a[k].ls);
		if(a[k].rs!=-1) q.push(a[k].rs);
	}
}
signed main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i].ls>>a[i].rs;
	for(int i=0;i<n;i++) cin>>b[i];
	sort(b,b+n);
	pos=0;
	dfs(0);
	pos=0;
	bfs(0);
	return 0;
}