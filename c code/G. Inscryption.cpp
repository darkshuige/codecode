#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
int a[maxn];
int p,q,n,flag;
void dfs(int now,int pp,int qq)
{
	if(flag==1) return;
	if(qq<=0) return ;
	if(now==n)
	{
		flag=1;
		if(pp*q>p*qq)
		{
			p=pp;q=qq;
		}
		return ;
	}
	while(a[now]==1)
	{
		now++;
		pp++;
		qq--;
	}
	while(a[now]==-1)
	{
		now++;
		qq--;
	}
	if(a[now]==0)
	{
		dfs(now+1,pp,qq-1);
		dfs(now+1,pp+1,qq+1);
	}
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		p=1,q=1;
		flag=0;
		cin>>n;
		for(int i=0;i<n;i++)
		 cin>>a[i];	
		dfs(0,1,1);
		if(flag==0)
		 cout<<-1<<endl;
		else
		{
			int g=__gcd(p,q);
			p/=g,q/=g;
			cout<<p<<" "<<q<<endl;
		}
		 
	}
	return 0;
}
