#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
const int maxn=2000;
int dp[maxn][maxn]={0};
signed main()//�ö�̬�滮��⣬dp[i][j]��ʾa�ַ�������iλ��b�ַ�������jλʱ�����Ӵ�
           // ��a[i]==b[j]��ʱ�� dp[i][j]=dp[i-1][j-1]+1��֮�����0
           //ʱ�临�Ӷ�ΪO(a.length*b.length) 
           //��Ҫʵ�������һ���Լ����У���ö���ҵ�maΪ���ʱ��i��j������ǰö�٣�ֱ��a[i]!=b[j]
		   //��������Ӵ�ͬ�� 
{
	jiasu;
	string a="1324564313216546321316548978";
	string b="4134135465134687465321321464654654513215";
	int ma=0;
	for(int i=1;i<=a.size();i++)
	{
		for(int j=1;j<=b.size();j++)
		{
			if(a[i]==b[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=0;
			}
			ma=max(ma,dp[i][j]);
		}
	}
	cout<<ma<<endl;
	return 0;
} 
