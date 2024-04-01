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

int N, M, w[maxn][maxn];
int d[maxn];
bool used[maxn];
int maxD[maxn][maxn];   //MST�д�i->j�����Ȩֵ
int pre[maxn];          //ĳһ�㸸�ڵ�
bool mst[maxn][maxn];   //�õ��Ƿ��Ѿ���MST��
typedef pair<int, int> P;
int Prim(int s){
    fill(d, d+maxn, inf); ms(maxD, 0);
    ms(used, 0); ms(mst, 0);
    fill(pre, pre+maxn, s);
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(d[s]=0, s));
    int res = 0;
    while(!q.empty())
	{
        P cur = q.top();
        q.pop();
        int u = cur.second;
        if(used[u]) continue;
        used[u] = true, res += d[u];
        
        mst[u][pre[u]] = mst[pre[u]][u] = true; //���뵽MST��
        for(int v = 1; v <= N; ++v)
		{
            if(used[v] && w[u][v]<inf)          //ֻ����MST�е�
                maxD[u][v] = maxD[v][u] = max(maxD[pre[u]][u], d[u]);
            if(w[u][v] < d[v]){
                d[v] = w[u][v];
                pre[v] = u;                     //���¸��ڵ�
                q.push(P(d[v], v));
            }
        }
    }
    return res;
}

int main()
{
    int T, a, b, c;
    cin >> T;
    while(T--)
	{
        fill(w[0], w[0]+maxn*maxn, inf);
        cin >> N >> M;
        while(M--)
		{
            cin >> a >> b >> c;
            w[a][b] = w[b][a] = c;
        }
        int ans = Prim(1);
        bool flag = false;  //��С�������Ƿ������С������
        for(int u = 1; u <= N && !flag; ++u)
		{
            for(int v = 1; v <= N; ++v)
			{
                if(mst[u][v] || w[u][v]==inf)
                    continue;
                if(w[u][v] == maxD[u][v])
				{
                    flag = true;
                    break;
                }
            }
        }
        if(flag) cout << "Not Unique!\n";
        else cout << ans << endl;
    }
	return 0;
}
//����˵һ������С��������˼·
//���������С������������ö��ÿ��������С�������ϵıߣ����������߷ŵ���С���������棬Ȼ���һ�����γɻ�����ô������������·��ȡ��һ�����·�������¼������һ���ߣ����������ǵõ���Ȩֵ���Ǵ�С��������Ȩֵ��
//
//ͨ����дPrim��Kruskal������ʵ��, �������Ƕ�Prim���и�д, ��Ҫ���弸������
//mst[i][j] : ��ʾ�ñ��Ƿ�����MST��
//pre[i] : ��ʾ i �ĸ��ڵ�
//maxd[i][j] : ��ʾMST�д�i -> j �����ֵ
//
//������ص���������maxd, �����õ��˶�̬�滮��˼��
//maxD[u][v] = max(maxD[pre[u]][u], d[u])
//
//���ж���С�������Ƿ���ڴ�С������, ö������δʹ�õı�, �жϸñ�<i, j> Ȩֵ�Ƿ����maxd[i][j]����
//ɾ�������߱�����ԭ��i,j��������ߣ����п��ܴ�С������������Ҫɾ�Ĵ�С��������ı߳���һ������ô��˵����С��������ֹһ����
