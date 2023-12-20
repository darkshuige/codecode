#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=110;
const int mod=998244353;
struct node
{
	int id;
	int sc;
}a[maxn];
int sum[maxn];
int flag[maxn][maxn];
int cmp(const node a,const node b)
{
	return a.sc>b.sc;
}
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	int ma=INT_MIN;
	int pos=-1;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].sc;
		a[i].id=i;	
	}
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		sum[i]+=i;
		memset(flag,0,sizeof flag);
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='o')
			{
				sum[i]+=a[j+1].sc;
				flag[i][j+1]=1;
			}
		}
		if(sum[i]>ma)
		{
			ma=sum[i];
			pos=i;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		int k=1;
		if(i==pos)
		{
			cout<<0<<endl;
			continue;
		}
		while(sum[i]<=ma)
		{
			if(flag[k][i]==0)
			{
				flag[k][i]=1;
				sum[i]+=a[k].sc;
				cnt++;
			}
			k++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
