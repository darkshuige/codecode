#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define rep(i,a,b) for(int i=a;i<=b;i++) 
using namespace std;
const int N = 110,M=2e4+10,INF=1e8;
int n,m,r;
int d[N][N],bd[N][N],g[N][N];
int pre[N],bpre[N];
int dfn[N],low[N],timestamp,stk[N],top;
int id[N],scc_cnt;
bool st[N],ins[N];
void dfs(int u)
{
	st[u]=true;
	for(int i=1;i<=n;++i) 
		if(d[u][i]<INF&&!st[i])
			dfs(i); 
}
bool check_con()
{
	memset(st,0,sizeof st);
	dfs(r);
	rep(i,1,n) 
		if(!st[i]) 
			return false;
	return true;
}
void tarjan(int u)
{
	dfn[u]=low[u]=++timestamp;
	stk[++top]=u;ins[u]=true;
	
	int j=pre[u];
	if(!dfn[j])
	{
		tarjan(j);
		low[u]=min(low[u],low[j]);
	}
	else if(ins[j]) low[u]=min(low[u],dfn[j]);
	if(low[u]==dfn[u])
	{
		int y;
		scc_cnt ++;
		do
		{
			y=stk[top --];
			ins[y]=false;
			id[y]=scc_cnt;
		}while(y!=u);
	}
}
int zhuliu()
{
	int ans = 0; 
	while(true)
	{
		for(int i=1;i<=n;++i)
		{
			pre[i]=i;
			for(int j=1;j<=n;++j)
				if(d[pre[i]][i] > d[j][i])
					pre[i]=j;
		}
		memset(dfn,0,sizeof dfn);
		timestamp=scc_cnt=0;
		for(int i=1;i<=n;++i) 
			if(!dfn[i])
				tarjan(i);
		if(scc_cnt == n)
		{
			for(int i=1;i<=n;++i) 
			{
				if(i==r) continue;
				ans += d[pre[i]][i];
			}
			break ;
		}
		for(int i=1;i<=n;++i)
		{
			if(i==r) continue;
			if(id[pre[i]] == id[i])
			{ 
				ans += d[pre[i]][i];
			}
		}
		for(int i=1;i<=scc_cnt;++i)
			for(int j=1;j<=scc_cnt;++j)
				bd[i][j]=INF;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(d[i][j] < INF && id[i]!=id[j])
				{
					int a=id[i],b=id[j];
					if(id[pre[j]]==id[j])
						bd[a][b]=min(bd[a][b],d[i][j]-d[pre[j]][j]);
					else bd[a][b]=min(bd[a][b],d[i][j]);
				}
			}
		}
		r=id[r];
		n = scc_cnt;
		memcpy(d,bd,sizeof d);	
	}
	return ans;
}
signed main()
{
	cin>>n>>m>>r;
	rep(i,1,m) 
	{
		int u,v,w;
		cin>>u>>v>>w;
		d[u][v]=min(d[u][v],w);
	}
	if(!check_con()) puts("-1");
	else cout<<zhuliu()<<endl;
	return 0;
}
//�����㷨
//����ͼ����Prim�㷨��������ͼ����С������
//
//��С����ͼ
//����ͼ��
//
//������
//���˸��ڵ��⣬ÿ�������Ϊ1
//��ĳ����Ϊ����һ�������������Ȩ֮��Ϊͼ����������ͼ������С�ĳ�Ϊ��С����ͼ��
//
//�����㷨 O ( n m ) O(nm)O(nm)
//(1) ���˸��ڵ����ÿ����ѡȡһ����Ȩ��С�����
//
//(2)�жϵ�ǰ(ѡ���ı�)��ɵ�ͼ�����޻�
//
//? 1.���޻�����˵����ǰͼ�Ѿ�Ϊ����õ���С���������㷨����
//
//? 2.���л������е�(3)��
//
//(3)�������ͼ����ǿ��ͨ�������㣬�õ���ͼG �� G'G 
//��
// ,����G �� G'G 
//��
// �е����б�
//
//? 1.����ǻ��еıߣ�ֱ��ɾȥ
//
//? 2.����յ��ڻ���(�������ĵ�)�����´˱�ȨȨֵΪW ? W �� �� W-W_{����}W?W 
//����
//?
// 
//
//? 3.�����ߣ�����
//
//Ȼ�������(1)��ʼ����
