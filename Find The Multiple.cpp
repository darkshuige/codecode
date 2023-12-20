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
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=20;
int a[maxn][maxn];
int n;
int flag;
void dfs(int now)
{
	if(flag==1) return ;
	if(now%n==0)
	{
		cout<<now<<endl;
		flag=1;
		return ;
	}
	if(now<=inf/10)
	{
		dfs(now*10);
		dfs(now*10+1);	
	}
}
signed main()
{
	jiasu;
	while(cin>>n)
	{
		if(n==0) break;
		flag=0;
		dfs(1);
	}
	return 0;
}
