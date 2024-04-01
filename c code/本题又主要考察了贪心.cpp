#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cou.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200;
int a[maxn];
int n,m;
vector<pair<int,int> >d;
int ans;
void dfs(int now)
{
	if(now==m)
	{
		int rank=1;
		int kk=a[1];
		for(int i=1;i<=n;i++)
		 if(a[i]>kk) rank++;
		ans=min(ans,rank);
		return ;
	}
	int a1=d[now].first,b1=d[now].second;
	for(int i=0;i<=2;i++)
	{
		if(i==0)
		{
			a[a1]+=3;
		}
		else if(i==1)
		{
			a[b1]+=3;
		}
		else if(i==2)
		{
			a[a1]++;
			a[b1]++;
		}
		dfs(now+1);
		if(i==0)
		{
			a[a1]-=3;
		}
		else if(i==1)
		{
			a[b1]-=3;
		}
		else if(i==2)
		{
			a[a1]--;
			a[b1]--;
		}
	}
}
signed main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		d.clear();
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			d.push_back({a,b});
		}
		ans=INT_MAX;
		dfs(0);
		cout<<ans<<endl;
	}
    return 0;
}