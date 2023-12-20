#include<bits/stdc++.h>
using namespace std;
int s[110][110];
int n,m,k;
int cnt=0;
void dfs(int x, int y)
{
    cnt++;
    s[x][y] = 0;
    if(s[x-1][y]==1) dfs(x-1,y);
    if(s[x+1][y]==1) dfs(x+1,y);
    if(s[x][y-1]==1) dfs(x,y-1);
    if(s[x][y+1]==1) dfs(x,y+1);
    return;
}
int main()
{
    while(~scanf("%d %d %d",&n,&m,&k))
	{
        int maxc = 0;
        memset(s,0,sizeof s);
        int x, y;
        for(int i = 0; i < k; i++)
		{
            scanf("%d %d", &x, &y);
            s[x][y] = 1;
        }
        for(int i = 1; i <= n; i++)
		{
            for(int j = 1; j <= m; j++)
			{
                if(s[i][j]==1)
				{
                    cnt = 0;
                    dfs(i,j);
                    maxc = max(maxc,cnt);
                }
            }
        }
        printf("%d\n", maxc);
    }
	return 0;
}
