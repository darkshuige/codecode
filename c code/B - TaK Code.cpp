#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=105;
char a[maxn][maxn];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>a[i][j];
	for(int i=1;i<=n-8;i++)
	{
		for(int j=1;j<=m-8;j++)
		{
			if(a[i][j]=='#' && a[i][j+1]=='#' && a[i][j+2]=='#'
			&& a[i+1][j]=='#' && a[i+1][j+1]=='#' && a[i+1][j+2]=='#'
			&& a[i+2][j]=='#' && a[i+2][j+1]=='#' && a[i+2][j+2]=='#'
			&& a[i][j+3]=='.' && a[i+1][j+3]=='.' && a[i+2][j+3]=='.'
			&& a[i+3][j]=='.' && a[i+3][j+1]=='.' && a[i+3][j+2]=='.'
			&& a[i+3][j+3]=='.'
			
			&& a[i+6][j+6]=='#' && a[i+6][j+7]=='#' && a[i+6][j+8]=='#'
			&& a[i+7][j+6]=='#' && a[i+7][j+7]=='#' && a[i+7][j+8]=='#'
			&& a[i+8][j+6]=='#' && a[i+8][j+7]=='#' && a[i+8][j+8]=='#'
			&& a[i+5][j+6]=='.' && a[i+5][j+7]=='.' && a[i+5][j+8]=='.'
			&& a[i+6][j+5]=='.' && a[i+7][j+5]=='.' && a[i+8][j+5]=='.'
			&& a[i+5][j+5]=='.')
			{
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	return 0;
} 
