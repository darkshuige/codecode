#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=110;
int n,m,k,d;
bool vis[maxn][maxn][1005];
struct castle
{
	char c;
	int t,v;
}mp[maxn][maxn];
struct node
{
	int g,x,y;
};
int dx[5] = { 0,0,-1,1,0 };
int dy[5] = { -1,1,0,0,0 };
void init()
{
	memset(vis, 0, sizeof vis);
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            mp[i][j].t = 0;
            mp[i][j].v = 0;
        }
    }
}
int bfs()//0 0 µ½ n m 
{
	if(mp[0][0].t!=0) return -1;
	node e;
	e.g=0;
	e.x=0;
	e.y=0;
	queue<node>q;
	q.push(e);
	vis[0][0][0]=1;
	while(!q.empty())
	{
		node cur=q.front();q.pop();
		int x=cur.x,y=cur.y;
		if(cur.g>d) break;
		for(int i=0;i<5;i++)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<0 || xx>n || yy<0 || yy>m) continue;
			bool flag=0;
			node ne=cur;
			ne.g++;
			if(vis[xx][yy][ne.g]==1) continue;
			if(mp[xx][yy].t) continue;
			if(xx==n && yy==m) return ne.g;
			for(int cx=xx-1;cx>=0;cx--)
			{
				if(mp[cx][yy].t!=0)
				{
					int L=xx-cx;
					if(mp[cx][yy].c=='S' && L%mp[cx][yy].v==0)
					{
						int t0=L/mp[cx][yy].v;
						int dt=ne.g-t0;
						if(dt>=0 && (dt%mp[cx][yy].t==0)) flag=1;
					}
					break;
				}
			}
			for (int cx = xx + 1; cx <= m; cx++)
            {
                if (mp[cx][yy].t != 0)
                {
                    int L = cx - xx;
                    if (mp[cx][yy].c == 'N'&&L%mp[cx][yy].v == 0)
                    {
                        int t0 = L / mp[cx][yy].v;
                        int dt = ne.g - t0;
                        if (dt >= 0 && (dt%mp[cx][yy].t == 0)) flag = true;
                    }
                    break;
                }
            }
            for (int cy = yy - 1; cy >= 0; cy--)
            {
                if (mp[xx][cy].t != 0)
                {
                    int L = yy - cy;
                    if (mp[xx][cy].c == 'E'&&L%mp[xx][cy].v == 0)
                    {
                        int t0 = L / mp[xx][cy].v;
                        int dt = ne.g - t0;
                        if (dt >= 0 && (dt%mp[xx][cy].t == 0)) flag = true;
                    }
                    break;
                }
            }
            for (int cy = yy + 1; cy <= n; cy++)
            {
                if (mp[xx][cy].t != 0)
                {
                    int L = cy - yy;
                    if (mp[xx][cy].c == 'W'&&L%mp[xx][cy].v == 0)
                    {
                        int t0 = L / mp[xx][cy].v;
                        int dt = ne.g - t0;
                        if (dt >= 0 && (dt%mp[xx][cy].t == 0)) flag = true;
                    }
                    break;
                }
            }
            if(flag) continue;
            ne.x=xx;
            ne.y=yy;
            q.push(ne);
            vis[xx][yy][ne.g]=1;
		}
	}
	return -1;
}
signed main()
{
	jiasu;
	while(cin>>n>>m>>k>>d)
	{
		init();
		for(int i=0;i<k;i++)
		{
			char c;
			int t,v,x,y;
			cin>>c>>t>>v>>x>>y;
			mp[x][y].c=c;
			mp[x][y].t=t;
			mp[x][y].v=v;
		}
		int ans=bfs();
		if(ans==-1)
		 cout<<"Bad luck!"<<endl;
		else
		 cout<<ans<<endl;	
	}
	
	return 0;
}
