#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=150005;
const int maxm=305;
int f[2][maxn];//压缩
int a[maxm],b[maxm],ti[maxm];
deque<int>de;
signed main()
{
	int n,m,d;
	cin>>n>>m>>d;
	for(int i=1;i<=m;i++)
	 cin>>a[i]>>b[i]>>ti[i];
	memset(f,-inf,sizeof f);
	for(int i=1;i<=n;i++)
	 f[0][i]=0;
	for(int i=1;i<=m;i++)
	{
		int now=i&1,last=(i-1)&1;
		de.clear();
		for(int j=1;j<=n;j++)
		{
			while(!de.empty() && f[last][j]>=f[last][de.back()]) de.pop_back();
			de.push_back(j);
			if(de.front()<j-(ti[i]-ti[i-1])*d) de.pop_front();
			f[now][j]=f[last][de.front()]+b[i]-abs(a[i]-j);
		}
		de.clear();
		for(int j=n;j<=1;j--)//第j位置，窗口左滑
		{
			while(!de.empty() && f[last][j]>=f[last][de.front()]) de.pop_front();
			de.push_front(j);
			if(de.back()>j+(ti[i]-ti[i-1])*d) de.pop_back();
			f[now][j]=max(f[now][j],f[last][de.back()]+b[i]-abs(a[i]-j));
		}
	}
	int ans=-1e18;
	for(int i=1;i<=n;i++)
	 ans=max(ans,f[m&1][i]);
	cout<<ans<<endl;
	return 0;
}