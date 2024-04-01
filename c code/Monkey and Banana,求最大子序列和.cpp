#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1000;
int dp[maxn];
struct node
{
	int x,y,z;
}a[maxn];
int cmp(node a,node b)
{
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
signed main()
{
	jiasu;
	int n;
	int t=0;
	while(cin>>n)
	{
		t++;
		if(n==0) break;
		memset(dp,0,sizeof dp);
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			int xx,yy,zz;
			cin>>xx>>yy>>zz;
			a[cnt++]={xx,yy,zz};
			a[cnt++]={xx,zz,yy};
			a[cnt++]={yy,zz,xx};
			a[cnt++]={yy,xx,zz};
			a[cnt++]={zz,xx,yy};
			a[cnt++]={zz,yy,xx};
		}
		sort(a,a+cnt,cmp);
		for(int i=0;i<cnt;i++) dp[i]=a[i].z;
		int ma=INT_MIN;
		for(int i=0;i<cnt;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[j].x<a[i].x && a[j].y<a[i].y)
				{
					dp[i]=max(dp[i],dp[j]+a[i].z);
					ma=max(ma,dp[i]);
				}
			}
		}
		cout<<"Case "<<t<<": maximum height = "<<ma<<endl;
	}
	return 0;
}