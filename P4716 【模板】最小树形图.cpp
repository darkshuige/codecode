#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1010;
int in[maxn],vis[maxn],id[maxn],pre[maxn];
//��С����ͼ����С�������������������С����ͼ������ͼ 
struct edges////���������߾�Ҫ<n nҪ���n+1������++tnҪ���tn++ 
{
	int u,v,w;
}edge[maxn*maxn];
int n,m,pos,root,u,v,w;
int g[maxn][maxn];
int zhuliu(int root,int n,int m)//��1��n��� 
{
    int res = 0;//resͳ�Ʊ�Ȩ�͡�
    while(true)
	{
        for(int i = 1; i<=n; ++ i)in[i] = INF, id[i] = vis[i] = -1;//��ʼ��������ĵȡ�
        for(int i = 0; i < m; ++ i)
		{
            u = edge[i].u, v = edge[i].v, w = edge[i].w;
            if(u != v && w < in[v])
			{
                in[v] = w;
                pre[v] = u;
            }
        }
        for(int i = 1; i<=n; ++ i)
		{
            if(i != root && in[i] == INF)
			{
                //˵����������ߣ��޷���������ͼ��
                return -1;
            }
        }
        in[root] = 0;
        
        int tn = 0;//�µı�š�
        for(int i = 1; i<=n; ++ i)
		{
            res += in[i];//ͳ��������ġ�
            v = i;
            while(vis[v] != i && id[v] == -1 && v != root)
			{
                vis[v] = i;
                v = pre[v];//���ϵ���ǰ����㣬֪�����µ�����㡣���ǻ���������vis[v] = iʱ�����˳������ص���㡣
            }
            if(v != root && id[v] == -1)
			{
                //˵��������rootΪ����㡣������������
                id[v] = ++tn;  //�Ӳ������������ʽ��λ��ҲҪ���� 
                for(u = pre[v]; u != v; u = pre[u])id[u] = tn;//���¸����򻷱�ţ�����֮�����㡣
            }
        }
        if(tn == 0)break;//˵��û�����±�ţ������������򻷡�
        
        for(int i = 1; i<=n; ++ i)
		{
            if(id[i] == -1)
			{
                id[i] = ++tn;//��δ���±�ŵ�Ҳ���±�ţ����ڴ���
            }
        }
        int i = 0;
        while(i < m)
		{
            int vv = edge[i].v;//������߻�������ԭ���ı�ţ���������ȡ������յ㡣
            //��ȡ���µı�š�
            edge[i].u = id[edge[i].u], edge[i].v = id[edge[i].v];
            if(edge[i].u != edge[i].v)
			{
                //���￴���ǻ���һ���뻷�ڵ�v�㣬����������Ҫ��ȥ�������Ȩ��
                //�������Ա����ظ����㡣
                edge[i++].w -= in[vv];//����Ȩֵ����Ϊ����Ѿ����ۼ��ˡ�
            }
            else
			{
                //�����򻷻����׳���
                swap(edge[i],edge[--m]);
            }
        }
        n = tn;//�����µĽ��������
        root = id[root];//���¸�����š�
    }
    return res;
}
signed main()
{
	jiasu;
	memset(g,INF,sizeof g);
	cin>>n>>m>>root;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==b) continue;
		g[a][b]=min(g[a][b],c);
	}
	m=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(g[i][j]!=INF)
			{
				edge[m].u=i;edge[m].v=j;edge[m++].w=g[i][j];
			}
		}
	}
	cout<<zhuliu(root,n,m)<<endl;
	return 0;
}
