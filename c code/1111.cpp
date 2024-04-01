#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,m;
    int a[1005],b[1005],c[1005],dp[10005];
    while(cin>>n>>m)
    {
        for(int i=0; i<n; i++)
         cin>>a[i];
        for(int i=0; i<n; i++)
         cin>>b[i];
        int abs=0,sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>c[i];
            abs+=c[i]*a[i];
            sum+=c[i]*b[i];
        }
        if(abs<m)
            printf("Impossible\n");
        else
        {
            for (int i = 1; i <= m; i++)
                dp[i] = sum;
            	dp[0] = 0;
	            for (int i = 0; i < n; i++)
	            {
	                for (int j = m - 1; j >= 0; j--)
	                {
	                    if (dp[j] != sum)
	                    {
	                        for (int k = 1; k <= c[i]; k++)
	                        {
	                            if (j + k * a[i] >= m)
	                                dp[m] = min(dp[m], dp[j] + k * b[i]);
	                            else
	                                dp[j + k * a[i]] = min(dp[j + k * a[i]], dp[j] + k * b[i]);
	                        }
	                    }
	                }
	            }
	            printf("%d\n", dp[m]);
        }
    }
    return 0;
}
