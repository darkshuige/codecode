#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
const int maxn=600;
char a[maxn][maxn];
int n,m;
int check1(int i,int j)
{
	if(i-4<1) return 0;
	if(a[i][j]=='#'
	&& a[i-1][j]=='#'
	&& a[i-2][j]=='#' && a[i-2][j+1]=='#' && a[i-2][j+2]=='#'
	&& a[i-3][j]=='#' && a[i-3][j+2]=='#' 
	&& a[i-4][j]=='#' && a[i-4][j+1]=='#' && a[i-4][j+2]=='#')
	{	
		a[i][j]='.';
		a[i-1][j]='.';
		a[i-2][j]='.';  a[i-2][j+1]='.';  a[i-2][j+2]='.';
		a[i-3][j]='.';  a[i-3][j+2]='.'; 
		a[i-4][j]='.';  a[i-4][j+1]='.';  a[i-4][j+2]='.';
		return 1;
	} 
	else return 0;
}
int check2(int i,int j)
{
	if(i-4<1) return 0;
	if(j-2<1) return 0;
	if(a[i][j]=='#'
	&& a[i-1][j]=='#'
	&& a[i-2][j]=='#' && a[i-2][j-1]=='#'
	&& a[i-3][j]=='#'
	&& a[i-4][j]=='#' && a[i-4][j-1]=='#' && a[i-4][j-2]=='#')
	{	
		a[i][j]='.';
		a[i-1][j]='.';
		a[i-2][j]='.';  a[i-2][j-1]='.';;
		a[i-3][j]='.';; 
		a[i-4][j]='.';  a[i-4][j-1]='.';  a[i-4][j-2]='.';
		return 1;
	} 
	else return 0;
}
int check3(int i,int j)
{
	if(i-4<1) return 0;
	if(a[i][j]=='#' && a[i][j+1]=='#' && a[i][j+2]=='#'
	&& a[i-1][j]=='#' && a[i-1][j+2]=='#'
	&& a[i-2][j]=='#' && a[i-2][j+1]=='#' && a[i-2][j+2]=='#'
	&& a[i-3][j]=='#' && a[i-3][j+2]=='#' 
	&& a[i-4][j]=='#' && a[i-4][j+1]=='#' && a[i-4][j+2]=='#')
	{	
		a[i][j]='.'; a[i][j+1]='.'; a[i][j+2]='.';
		a[i-1][j]='.';  a[i-1][j+2]='.';  
		a[i-2][j]='.';  a[i-2][j+1]='.';  a[i-2][j+2]='.';
		a[i-3][j]='.';  a[i-3][j+2]='.'; 
		a[i-4][j]='.';  a[i-4][j+1]='.';  a[i-4][j+2]='.';
		return 1;
	} 
	else return 0;
}
void show()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		 cout<<a[i][j];
		cout<<endl;
	}
	cout<<endl;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>a[i][j];
	int sum1=0,sum2=0,sum3=0;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if(check3(i,j)) sum3++;
			if(check1(i,j)) sum1++;
			if(check2(i,j)) sum2++;
		}
	}
	cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
	return 0;
}