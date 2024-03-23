#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
const int maxn=600;
char a[maxn][maxn];
int sum1,sum2,sum3,flag;
int n,m;
int f[maxn][maxn][maxn][maxn][maxn];
int check1(int i,int j)
{
	if(a[i][j]=='#' && a[i][j+1]=='#' && a[i][j+2]=='#'
	&& a[i+1][j]=='#' && a[i+1][j+2]=='#'
	&& a[i+2][j]=='#' && a[i+2][j+1]=='#' && a[i+2][j+2]=='#'
	&& a[i+3][j]=='#'
	&& a[i+4][j]=='#')
	 return 1;
	else return 0;
}
int check2(int i,int j)
{
	if(a[i][j]=='#' && a[i][j+1]=='#' && a[i][j+2]=='#'
	&& a[i+1][j+2]=='#'
	&& a[i+2][j+1]=='#' && a[i+2][j+2]=='#'
	&& a[i+3][j+2]=='#'
	&& a[i+4][j+2]=='#')
		return 1;
	else return 0;
}
int check3(int i,int j)
{
	if(a[i][j]=='#' && a[i][j+1]=='#' && a[i][j+2]=='#'
	&& a[i+1][j]=='#' && a[i+1][j+2]=='#'
	&& a[i+2][j]=='#' && a[i+2][j+1]=='#' && a[i+2][j+2]=='#' 
	&& a[i+3][j]=='#' && a[i+3][j+2]=='#'
	&& a[i+4][j]=='#' && a[i+4][j+1]=='#' && a[i+4][j+2]=='#')
		return 1;
	else return 0;
}
signed main()
{
	jiasu;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	 {
	 	cin>>a[i][j];
	 	if(a[i][j]=='#') sum++;
	 }
	flag=0,sum1=sum2=sum3=0;
	cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
    return 0;
} 
