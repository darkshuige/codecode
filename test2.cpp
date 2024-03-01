#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000;
char mat[maxn][maxn];
int n,m;
int count()
{
	int ans = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (mat[i][j] == '*') 
			{
				ans++;
				int left = 0;
				int right = 0;
				while (i + left < n && i + right < n && j - left >= 0 && j + right < m && mat[i + left][j - left] == '*' && mat[i + right][j + right] == '*') 
				{
					int height = 1;
					while (i - height >= 0 && mat[i - height][j - left] == '*' && mat[i - height][j + right] == '*') 
					{
						bool flag = true;
						for (int k = j - left + 1; k < j + right; k++) 
						{
							if (mat[i - height][k] != '*') 
							{
								flag = false;
								break;
							}
						}
						if (!flag) 
						 break;
						ans++;
						height++;
					}
					left++;
					right++;
				}
			}
		}
	}
	return ans;
}
signed main() 
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		 cin >> mat[i][j];
	}
	int ans = count();
	cout << ans << endl;
	return 0;
}
