#include<iostream>
#include<vector>
using namespace std;
int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> steps(m);
    for(int i = 0; i < m; i++) 
    {
    	cin >> steps[i];
    	steps[i]%=n;
	}
    vector<vector<bool>> dp(m+1, vector<bool>(n, false));
    dp[0][0] = true; //dp[i][j]表示第i轮结束后是否能走j步到1
    for(int i = 1; i <= m; i++) 
     for(int j = 0; j < n; j++) 
      dp[i][j] = dp[i-1][(j-steps[i-1]+n)%n] || dp[i-1][(j+steps[i-1])%n];
    if(dp[m][0]) 
     cout << "yes" << endl;
	else 
     cout << "no" << endl;
    return 0;
}
