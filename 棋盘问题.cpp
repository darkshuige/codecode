 #include  <map>
 #include  <set>
 #include  <cmath>
 #include  <queue>
 #include  <cstdio>
 #include  <vector>
 #include  <climits>
 #include  <cstring>
 #include  <cstdlib>
 #include  <iostream>
 #include  <algorithm>
 #define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
 #define int long long
 #define endl "\n"
using namespace std;
const int maxn=10;
char a[maxn][maxn];
int b[maxn];
int c[maxn];
int ans;
int n,k;
void dfs(int now,int s)
{
	if(s==k)
	{
		ans++;
		return ;
	}
	if(now>=n) return ;
	dfs(now+1,s);
	for(int i=0;i<n;i++)
	{
		if(a[now][i]=='.') continue;
		if(b[now]) continue;
		if(c[i]) continue;
		b[now]=1,c[i]=1;
		dfs(now+1,s+1);
		b[now]=0,c[i]=0;
	}
}
signed main()
{
	while(cin>>n>>k)
	{
		if(n==-1 && k==-1) break;
		for(int i=0;i<n;i++)
		 for(int j=0;j<n;j++)
		  cin>>a[i][j];
		memset(b,0,sizeof b);memset(c,0,sizeof c);
		ans=0;
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
} 
