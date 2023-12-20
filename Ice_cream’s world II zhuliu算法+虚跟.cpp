#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000;
int in[maxn],vis[maxn],id[maxn],pre[maxn];
struct edges
{
	int u,v,w;
}edge[maxn*maxn];
int n,m,pos,root,u,v,w,tot,sum,minroot;
int g[maxn][maxn];
int zhuliu(int root,int n)
{
    int res = 0;//resͳ�Ʊ�Ȩ�͡�
    while(true)
	{
        for(int i = 0; i < n; ++ i) in[i] = INF, id[i] = vis[i] = -1;//��ʼ��������ĵȡ�
        for(int i = 0; i < tot; ++ i)
		{
            u = edge[i].u, v = edge[i].v, w = edge[i].w;
            if(u != v && w < in[v])
			{
                in[v] = w;
                pre[v] = u;
                if(u==root)
             	 minroot=i;
            }
        }
        for(int i = 0; i < n; ++ i)
		{
            if(i != root && in[i] == INF)
			{
                //˵����������ߣ��޷���������ͼ��
                return -1;
            }
        }
        in[root] = 0;
        
        int tn = 0;//�µı�š�
        for(int i = 0; i < n; ++ i)
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
                for(u = pre[v]; u != v; u = pre[u]) id[u] = tn;//���¸����򻷱�ţ�����֮�����㡣
                id[v] = tn++;//��Ϊ�Ǵ�0��ʼ�������������tn++��Ȼ��++tn�������Ǿ��λ��ҲҪ��һ�� 
            }
        }
        if(tn == 0)break;//˵��û�����±�ţ������������򻷡�
        
        for(int i = 0; i <n; ++ i)
		{
            if(id[i] == -1)
			{
                id[i] = tn++;//��δ���±�ŵ�Ҳ���±�ţ����ڴ���
            }
        }
        int i = 0;
        while(i < tot)
		{
            int vv = edge[i].v;//������߻�������ԭ���ı�ţ���������ȡ������յ㡣
            //��ȡ���µı�š�
            edge[i].u = id[edge[i].u], edge[i].v = id[edge[i].v];
            if(edge[i].u != edge[i].v)
			{
                //���￴���ǻ���һ���뻷�ڵ�v�㣬����������Ҫ��ȥ�������Ȩ��
                //�������Ա����ظ����㡣
                edge[i].w -= in[vv];//����Ȩֵ����Ϊ����Ѿ����ۼ��ˡ�
            }
            i++;
        }
        n = tn;//�����µĽ��������
        root = id[root];//���¸�����š�
    }
    return res;
}
void add(int a,int b,int c)
{
	edge[tot].u=a;
	edge[tot].v=b;
	edge[tot++].w=c;
}
signed main()
{
	jiasu;
	while(cin>>n>>m)
	{
		tot=sum=0;
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			add(a,b,c);
			sum+=c;
		}
		sum++;
		for(int i=0;i<n;i++)
		 add(n,i,sum);
		int ans=zhuliu(n,n+1);
		if(ans==-1 || ans>=2*sum)
		 cout<<"impossible"<<endl;
		else
		 cout<<ans-sum<<" "<<minroot-m<<endl;
		cout<<endl;
	}
	return 0;
}
