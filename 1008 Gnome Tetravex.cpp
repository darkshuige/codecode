#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=30;
int a[maxn][4];
int sum[maxn];
int ans[100];
int flag,n,cnt;
void dfs(int x)
{
	if(flag==1) return ;
	if(x==n*n+1)
	{
		flag=1;
		return ;
	}
	for(int i=0;i<cnt;i++)
	{
		if(sum[i]==0) continue; 
		if(x==1)
		{
			--sum[i];
			ans[x]=i;
			dfs(x+1);
			++sum[i];
		}
		else if(x<=n)
		{
			if(a[i][3]==a[ans[x-1]][1])
			{
				--sum[i];
				ans[x]=i;
				dfs(x+1);
				++sum[i];
			}
		}
		else if((x-1)%n==0)
		{
			if(a[i][0]==a[ans[x-n]][2])
			{
				--sum[i];
				ans[x]=i;
				dfs(x+1);
				++sum[i];
			}
		}
		else
		{
			if(a[i][0]==a[ans[x-n]][2] && a[i][3]==a[ans[x-1]][1])
			{
				--sum[i];
				ans[x]=i;
				dfs(x+1);
				++sum[i];
			}
		}
	}
}
signed main()
{
	jiasu;
	int pos=0;
	while(cin>>n)
	{
		if(n==0) break;
		memset(sum,0,sizeof sum);
		++pos;
		cnt=0;
		for(int i=0;i<n*n;i++)
		{
			int a1,a2,a3,a4;
			cin>>a1>>a2>>a3>>a4;
			int f=0;
			for(int j=0;j<cnt;j++)
			{
				if(a[j][0]==a1 && a[j][1]==a2 && a[j][2]==a3 && a[j][3]==a4)
				{
					++sum[j];
					f=1;
					break;
				}
			}
			if(f==0)
			{
				a[cnt][0]=a1,a[cnt][1]=a2,a[cnt][2]=a3,a[cnt][3]=a4;
				sum[cnt++]=1;
			}
		}
		flag=0;
		dfs(1);
		if(pos!=1)
		 cout<<endl;
		cout<<"Game "<<pos<<": ";
		if(flag)
		 cout<<"Possible"<<endl;
		else
		 cout<<"Impossible"<<endl;
	}
	return 0;
} 
