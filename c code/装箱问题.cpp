#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
int ans,n,x,y,a[200],r;
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a);
		a=(a*a);
		b>>=1;
	}
	return ans;
}
void dfs(int op,int r,int now)
{
	if(r<=0 && op<=n)
	{
		ans=max(ans,now);
		return ;
	}
	if(op>n)
	 return ;
	while(a[op]<x && a[op]<y)
	 op++;
	if(op>n)
	 return ;
	if(a[op]>=x)
	{
		a[op]-=x;
		r-=x;
		dfs(op,r,now-ksm(a[op]+x,2)+ksm(a[op],2));
		a[op]+=x;
		r+=x;
	}
	if(a[op]>=y)
	{
		a[op]-=y;
		r-=y;
		dfs(op,r,now-ksm(a[op]+y,2)+ksm(a[op],2));
		a[op]+=y;
		r+=y;
	}
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		cin>>n>>x>>y>>r;
		ans=-1;
		int kk=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			kk+=ksm(a[i],2);	
		}
		dfs(1,r,kk);
		cout<<ans<<endl;
	} 
	return 0;
}
