#include <bits/stdc++.h>//曼哈顿距离不行因为有墙壁火也不能穿墙 
using namespace std;
int n, m;
const int N = 1005;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

typedef struct 
{
    int x, y, s;
} node;

queue<node>J, F;
int ans;
char g[N][N];
bool st[N][N];

bool bfs() 
{
    while (!J.empty()) 
	{
        int Ft = F.size();
        while (Ft--) 
		{
            auto t = F.front();
            F.pop();
            for (int i = 0; i < 4; i++) 
			{
                int a = t.x + dx[i], b = t.y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == '.') 
				{
                    g[a][b] = 'F';
                    F.push({a, b, t.s + 1});
                }
            }
        }
        int Jt = J.size();
        while (Jt--) 
		{
            auto t = J.front();
            J.pop();
            if (t.x == n - 1 || t.x == 0 || t.y == 0 || t.y == m - 1) 
			{
                ans = t.s + 1;
                return true;
            }
            for (int i = 0; i < 4; i++) 
			{
                int a = t.x + dx[i], b = t.y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == '.' && !st[a][b]) 
				{
                    st[a][b] = true;
                    g[a][b] = 'J';
                    J.push({a, b, t.s + 1});
                }
            }
        }
    }
    return false;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) 
	{
        while (!J.empty()) J.pop();
        while (!F.empty()) F.pop();
        memset(st, 0, sizeof st);
        cin >> n >> m;
        for (int i = 0; i < n; i++) 
		{
            for (int j = 0; j < m; j++) 
			{
                cin >> g[i][j];
                if (g[i][j] == 'J') 
				{
                    J.push({i, j, 0});
                }
                if (g[i][j] == 'F') 
				{
                    F.push({i, j, 0});
                }
            }
        }
        if (bfs()) cout << ans << "\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}
