#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=5010;
const int mod=1e8;
int f[2][maxn],r[2][maxn],pre,now;
signed main()
{
	string a,b;
	cin>>a>>b;
	int n=a.size()-1,m=b.size()-1;
	a="#"+a; b="#"+b;
	now=1,pre=0;//用于滚动数组
	for(int k=0;k<m;k++)
	 r[0][k]=1;//初始化，长度为0最长子序列方案数为1（第一个序列长度为0）
	r[1][0]=1;////长度为0最长子序列方案数为1（第二个序列长度为0） 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[now][j]=max(f[pre][j],f[now][j-1]);//从左边和上面取大的
			r[now][j]=0;//后面的方案数都是由前面加过来的
			if(a[i]==b[j]) f[now][j]=max(f[now][j],f[pre][j-1]+1);
			if(a[i]==b[j] && f[now][j]==f[pre][j-1]+1) r[now][j]+=r[pre][j-1];//拿了第i和j个的情况下
			
			if(f[pre][j]==f[now][j]) r[now][j]+=r[pre][j];
			if(f[now][j-1]==f[now][j]) r[now][j]+=r[now][j-1];// 左边和上面的额情况
			
			if(f[pre][j-1]==f[now][j]) r[now][j]-=r[pre][j-1]; //如果a[i]!=b[j]且f[i-1][j-1]=k，就要减去它的方案数
			
			r[now][j]=(r[now][j]+mod)%mod;//+mod可以省略
		}
		now^=1; pre^=1;
	}
	cout<<f[pre][m]<<endl<<r[pre][m]<<endl;
    return 0;
}