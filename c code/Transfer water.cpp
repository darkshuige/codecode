#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2010;
int in[maxn],vis[maxn],id[maxn],pre[maxn];
//���й�ˮ��ϵ���˼Ҽ佨�ߣ����쳬��Դ��0����0��ÿ���˼�i��zi*X�ı߱�ʾ�û��˼��Լ��侮�Ļ��ѣ�֮�����������ͼ����С����ͼ�� 
struct edges//���������߾�Ҫ<n nҪ���n+1������++tnҪ���tn++ 
{
	int u,v,w;
}edge[maxn*maxn];
struct node
{
	int x,y,z;
}a[maxn];
int n,m,pos,root,u,v,w,x,y,z;
int g[maxn][maxn];
int zhuliu(int root,int n,int m)
{
    int res = 0;//resͳ�Ʊ�Ȩ�͡�
    while(true)
	{
        for(int i = 0; i<n; ++ i)in[i] = INF, id[i] = vis[i] = -1;//��ʼ��������ĵȡ�
        for(int i = 0; i < m; ++ i)
		{
            u = edge[i].u, v = edge[i].v, w = edge[i].w;
            if(u != v && w < in[v])
			{
                in[v] = w;
                pre[v] = u;
            }
        }
        for(int i = 0; i<n; ++ i)
		{
            if(i != root && in[i] == INF)
			{
                //˵����������ߣ��޷���������ͼ��
                return -1;
            }
        }
        in[root] = 0;
        
        int tn = 0;//�µı�š�
        for(int i = 0; i<n; ++ i)
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
                for(u = pre[v]; u != v; u = pre[u])id[u] = tn;//���¸����򻷱�ţ�����֮�����㡣
                id[v] = tn++;
            }
        }
        if(tn == 0)break;//˵��û�����±�ţ������������򻷡�
        
        for(int i = 0; i<n; ++ i)
         if(id[i] == -1)
          id[i] = tn++;//��δ���±�ŵ�Ҳ���±�ţ����ڴ���
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
int dis(int i,int j)
{
	if(a[i].z>=a[j].z)
	 return y*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+abs(a[i].z-a[j].z));
	else
	 return y*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+abs(a[i].z-a[j].z))+z;
}
void add(int a,int b,int c)
{
	edge[m].u=a;
	edge[m].v=b;
	edge[m++].w=c;
}
signed main()
{
	jiasu;
	while(cin>>n>>x>>y>>z)
	{
		if(n==0 && x==0 && y==0 && z==0) break;
		memset(g,INF,sizeof g);
		for(int i=1;i<=n;i++)
		 cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=0;j<k;j++)
			{
				int op;
				cin>>op;
				int d=dis(i,op);//i->op 
				if(i==op) continue;
				g[i][op]=min(g[i][op],d);
			}
		}	
		m=0;
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)
		  if(g[i][j]!=INF)
		   add(i,j,g[i][j]);
		for(int i=1;i<=n;i++)
		 add(0,i,a[i].z*x);
		root=0;
		int ans=zhuliu(0,n+1,m);
		if(ans==-1)
		 cout<<"poor XiaoA"<<endl;
		else
		 cout<<ans<<endl;
	}
	return 0;
}
