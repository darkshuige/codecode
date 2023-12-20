#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define ms(x, n) memset(x,n,sizeof(x));
typedef  long long LL;
const int inf = 1<<30;
const LL maxn = 110;

int N, M;
double w[maxn][maxn];
struct node{
    double x, y;
}vs[maxn];
double getDis(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool vis[maxn], flag[maxn];
int pre[maxn];

double zhuliu(int u){
    ms(vis, 0);
    double ans = 0;
    while(true){
        for(int i = 1; i <= N; ++i)
            if(i!=u && !flag[i]){
                w[i][i] = inf, pre[i] = i;
                for(int j = 1; j <= N; ++j)
                    if(!flag[j] && w[j][i] < w[pre[i]][i])
                        pre[i] = j;
                if(pre[i] == i) return -1;
            }

        int i;
        for(i = 1; i <= N; ++i){
            if(i!=u && !flag[i]){
                int j = i, cnt = 0;
                while(j!=u && pre[j]!=i && cnt<=N)
                    j = pre[j], ++cnt;
                if(j==u || cnt>N) continue;
                break;
            }
        }
        if(i > N){
            for(int i = 1; i <= N; ++i)
                if(i!=u && !flag[i])
                    ans += w[pre[i]][i];
            return ans;
        }

        int j = i;
        ms(vis, 0);
        do{
            ans += w[pre[j]][j], j = pre[j], vis[j] = flag[j] = true;
        }while(j != i);
        flag[i] = false;

        for(int k = 1; k <= N; ++k)
            if(vis[k]){
                for(int j = 1; j <= N; ++j)
                    if(!vis[j]){
                        if(w[i][j] > w[k][j])
                            w[i][j] = w[k][j];
                        if(w[j][k] < inf && w[j][k]-w[pre[k]][k] < w[j][i])
                            w[j][i] = w[j][k] - w[pre[k]][k];
                    }
            }
    }
    return ans;
}
int main()
{
    int a, b;
    while(scanf("%d%d",&N,&M)!=EOF)
	{
        ms(vis, 0); ms(flag, 0);
        fill(w[0], w[0]+maxn*maxn, inf);
        for(int i = 1; i <= N; ++i)
            scanf("%lf%lf",&vs[i].x,&vs[i].y);
        for(int i = 1; i <= M; ++i)
		{
            scanf("%d%d",&a,&b);
            w[a][b] = getDis(vs[a].x, vs[a].y, vs[b].x, vs[b].y);
        }
        double ans = zhuliu(1);
        if(ans==-1) printf("poor snoopy\n");
        else printf("%.2f\n",ans);
    }
	return 0;
}
