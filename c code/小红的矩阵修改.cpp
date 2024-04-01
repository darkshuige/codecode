#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100000;
char a[maxn];
int ans=INT_MAX;
int n,m;
int check(int x,int y)
{
	int pos=(x-1)*4+y;
	
}
void dfs(int pos,int now)
{
	int x=(pos-1)/4+1;
	int y=(pos-1)%4+1;
	if(x==n && y==m)
	{
		if(check(x,y))
		{
			ans=min(ans,now);
		}
	}
	
}
signed main()
{
    jiasu;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
     cin>>a[i];
	dfs(1,0);
	cout<<ans<<endl;
    return 0;
}
