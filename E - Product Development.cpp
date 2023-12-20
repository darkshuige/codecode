#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=110;
struct node
{
	int d;
	int op[10];
}a[maxn];
int ans,k,p,n;
int check(int sum[])
{
	for(int i=0;i<k;i++)
	{
		if(sum[i]<p)
		{
			return 0;
		}
	}
	return 1;
}
void dfs(int now,int s,int sum[])
{
	if(now>n) return ;
	if(s>ans) return ;
	if(check(sum))
	{
		ans=min(ans,s);
		return ;
	}
	int sumsum[10];
	for(int i=0;i<k;i++)
	 sumsum[i]=sum[i];
	for(int i=0;i<k;i++)
	 sumsum[i]+=a[now].op[i];
	dfs(now+1,s+a[now].d,sumsum);
	dfs(now+1,s,sum);
}
signed main()
{
	jiasu;
	cin>>n>>k>>p;
	int sum[10]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i].d;
		for(int j=0;j<k;j++)
		{
			cin>>a[i].op[j];
			sum[j]+=a[i].op[j];
		}
	}
	int flag=1;
	for(int i=0;i<k;i++)
	{
		if(sum[i]<p)
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	ans=inf;
	memset(sum,0,sizeof sum);
	dfs(0,0,sum);
	cout<<ans<<endl;
	return 0;
}
