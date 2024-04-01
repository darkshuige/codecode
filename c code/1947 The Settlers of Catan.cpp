#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=30;
int a[maxn][maxn];
int best,n;
void visit(int i,int l)
{
	best=max(best,l);
	for(int j=0;j<n;j++)
	{
		if(a[i][j]!=0)
		{
			a[i][j]=a[j][i]=0;
			visit(j,l+1);
			a[i][j]=a[j][i]=1;
		}
	}
}
signed main()
{
	int m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
		 break;
		memset(a,0,sizeof a);
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
		}
		best=0;
		for(int i=0;i<n;i++)
		{
			visit(i,0);
		}
		cout<<best<<endl;
	}
	return 0;
} 
