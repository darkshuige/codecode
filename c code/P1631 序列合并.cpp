#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn],id[maxn];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >q;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=1;i<=n;i++)
	 cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		q.push({a[1]+b[i],i});
		id[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		pair<int,int>p=q.top();
		q.pop();
		if(i!=0)
		 cout<<" ";
		cout<<p.first;
		q.push({a[++id[p.second]]+b[p.second],p.second});
	}
	return 0;
}
