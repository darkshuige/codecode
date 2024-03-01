#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
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
const int maxn=1005;
int dp[maxn][maxn];
signed main()
{
	jiasu;
    string a,b;
    while(cin>>a>>b)
    {
    	memset(dp,0,sizeof dp);
    	for(int i=1;i<=a.size();i++)
    	{
    		for(int j=1;j<=b.size();j++)
    		{
    			if(a[i-1]==b[j-1])
    			 dp[i][j]=dp[i-1][j-1]+1;
    			else
    			 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[a.size()][b.size()]<<endl;
	}
    return 0;
}