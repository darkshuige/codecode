#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
 
using namespace std;
 
typedef pair<int, int> PII;
typedef long long ll;
 
const int N = 3010, mod = 998244353;
 
int f[N][N];
 
int main()
{
	IOS
	string s;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	f[0][0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= i; j ++)
		{
			if(s[i] == '(')
			{
				if(j)f[i][j] = f[i - 1][j - 1];//选了左括号不可能为0 
			}
			else if(s[i] == ')')
			{
				f[i][j] = f[i - 1][j + 1];
			}
			else 
			{
				if(!j)f[i][j] = f[i - 1][j + 1];//当前是0只能是选的右括号 
				else f[i][j] = (f[i - 1][j - 1] + f[i - 1][j + 1]) % mod;
			}
		}
	}
	cout << f[n][0];
	
	return 0;
}
