#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=1000005;
int a[maxn];
int n,m,cnt=0;
void dfs(int i,int sum)
{
	if(i+1<n)
	{
		if(sum==m) 
		{
			cnt++;
			sum=0;
		}
	//	dfs(i+1,sum);
		dfs(i+1,sum+a[i]);
	}
}
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	cnt=0;
	dfs(0,0);
	cout<<cnt<<endl;
	return 0;
} 
