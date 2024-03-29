#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
//高斯消元法，用来解方程组
//1.枚举主元，找到下面不是1的一行
//2.交换两行，把这一行与主元行进行交换
//3.把某一行乘以一个非0的数，把主元系数变成1
//4.把某行的若干倍加到另一行上，把主元下面的系数变成0
const int maxn=110;
const double eps=1e-6;
int n;
double a[maxn][maxn];//增广矩阵
int gauss()
{ 
	for(int i=1;i<=n;i++)  //第i主元
	{
		for(int k=i;k<=n;k++) //换非0行
		  if(fabs(a[k][i])>eps)
		  {
		  	  swap(a[k],a[i]);
		  	  break;
		  }
		if(fabs(a[i][i])<eps) return 0; //无解
		for(int j=n+1;j>=i;j--) //变1
		 a[i][j]/=a[i][i];
		for(int k=i+1;k<=n;k++)
		 for(int j=n+1;j>=i;j--)
		  a[k][j]-=a[k][i]*a[i][j];//变0
	}
	for(int i=n-1;i>=1;i--) //回带
	 for(int j=i+1;j<=n;j++)
	  a[i][n+1]-=a[i][j]*a[j][n+1];
	return 1; //存在唯一解
}
signed main()
{
	jiasu;
	cin>>n;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n+1;j++)
	  cin>>a[i][j];
	if(gauss())
	{
		for(int i=1;i<n+1;i++)
		 cout<<fixed<<setprecision(2)<<a[i][n+1]<<endl;
	}
	else
	 cout<<"No Solution"<<endl;
	return 0;
}