#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2e5 + 10, INF = 1e9 + 10;
int n, k, p;
int c[150];//����
int a[150][10];//ÿһλ�ļ�ֵ
LL dp[100005];//Ŀ��Ϊiʱ�����ѵ���С����,i���55555��dp[i]���1e11
int m;//10����Ŀ��ֵ��ÿһλ��Ϊp
int main() 
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k >> p;
	for (int i = 1; i <= k; i++) 
	 m = m * 10 + p;//Ŀ��ֵ
	for (int i = 1; i <= n; i++) 
	{
		cin >> c[i];
		for (int j = 1; j <= k; j++) 
		 cin >> a[i][j];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= 0; j--)//555 
		{   //01����
			//ʮ����ת��
			int w[6] = {0};
			for (int x = j, l = 1; l <= k; l++, x /= 10) //l��ʾ�ڼ�λ�Ӻ���ǰ 
			{
				w[l] = max(0, x % 10 - a[i][l]);//����ÿһλ��ת��
			}
			int x = 0;
			for (int l = k; l > 0; l--) 
			 x = x * 10 + w[l];//ȷ��j��˭ת��  x�ͱ�ʾ����˶��� 
			//ʮ����ת��
			//01����
			dp[j] = min(dp[j], dp[x] + c[i]);//ѡ��i����Ŀ��Ϊjʱ��xת�Ƶ���С����
		}
	}
	cout << (dp[m] > 1e11 ? -1 : dp[m]);
	return 0;
}
