#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=15;
int p[maxn];//记录每一行在第几列;
int pie[maxn<<1],na[maxn<<1];//两个对角线
int c[maxn];//每一列 
int n,ans;
void dfs(int x)
{
	if(x>n)
	{
		ans++;
		if(ans<=3)
		{
			for(int i=1;i<=n;i++)
			{
				if(i!=1)
				 cout<<" ";
				cout<<p[i];
			}
			cout<<endl;	
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i] || pie[x+i] || na[x-i+n])
		 continue;
		c[i]=pie[x+i]=na[x-i+n]=1,p[x]=i;
		dfs(x+1);
		c[i]=pie[x+i]=na[x-i+n]=0;
	}
}
signed main()
{
	cin>>n;
	ans=0;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
