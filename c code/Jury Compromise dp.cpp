#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include<stack>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include<string>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=205;
const int maxm=30;
int n,m,base=400;//-400~+400 映射为0~800 400==一开始的0
int dp[maxn][maxm][810],p[maxn],d[maxn],no[maxn];
//dp[i][j][k]表示从前i个人中选j个人差值为k的时候和的最大值
//动态规划有多个条件的时候总是会吧一个条件作为一个变量加入dp函数里面
signed main()
{
	jiasu;
	int cnt=0;
	while(cin>>n>>m)
	{
		cnt++;
		if(n==0 && m==0) break;
		for(int i=1;i<=n;i++) cin>>p[i]>>d[i];
		cout<<"Jury #"<<cnt<<endl;
		memset(dp,-inf,sizeof dp);
		dp[0][0][400]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=m;j++)//可以一个人也不选 一定要从0开始走不然dp不下去
			{
				for(int k=0;k<805;k++)
				{
					dp[i][j][k]=dp[i-1][j][k];//不选第j个人，后面直接用max省的判断
					int t=k-(p[i]-d[i]);
					if(t<0 || t>=805) continue;
					if(j<1) continue;//并非多此一举下面会有j-1出现但是上面的转移是需要的
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][t]+p[i]+d[i]);//拿第j个人
				}
			}
		}
		int v=0;//找出k值最小的点
		while(dp[n][m][base-v]<0 && dp[n][m][base+v]<0) v++;
		//取不到的点都是负无穷，从0开始遍历就是离base最近的点也就是离映射值0最近的点
		if(dp[n][m][base-v]>dp[n][m][base+v]) v=base-v;
		else v=base+v;//找两边sum值大的那一边
		int psum=0,dsum=0;
		int i=n,j=m;
		stack<int>st;
		//dp是正向的找答案就反向找
		while(j)//直到全部找完j=0
		{
			if(dp[i][j][v]==dp[i-1][j][v])//说明j没取
			 i--;
			else
			{
				st.push(i);
				psum+=p[i];
				dsum+=d[i];
				v-=(p[i]-d[i]);
				i--; j--;
			}
		}
		cout<<"Best jury has value "<<psum<<" for prosecution and value "<<dsum<<" for defence: "<<endl;
		while(!st.empty())
		{
			cout<<" "<<st.top();
			st.pop();
		}
		cout<<endl<<endl;
	}
	return 0;
}