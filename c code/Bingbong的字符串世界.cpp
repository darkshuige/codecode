#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200005;
char s[maxn];
int nex[maxn][30];
int n,k;
int find(int l,string p)
{
	int first=1;
	for(auto ch:p)
	{
		if(first==1) l=nex[l][ch-'A'];//包括自己在内
		else if(first==0) l=nex[l+1][ch-'A'];//往后面找
		first=0;
		if(l==n+1) return l;//剪枝
	}
	return l;
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=n+1;i>=1;i--)
	{
		for(int j=0;j<=25;j++)
		{
			if(i==n+1) nex[i][j]=n+1;
			else nex[i][j]=nex[i+1][j];
		}
		nex[i][s[i]-'A']=i;
	}
	string ac="ACCEPT",wa="WA";
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int r1=find(i,ac),r2=find(i,wa);
		if(r1==n+1) continue;
		r1=max(r1,i+k-1);
		ans+=max((r2-r1),(int)0);
	}
	cout<<ans<<endl;
	return 0;
}