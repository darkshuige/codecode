#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000005;
int h[maxn],to[maxn],ne[maxn],ww[maxn],idx=0; //链式前向星
int vis[maxn],fa[maxn],w[maxn]; //访问标记，父节点，w把边权存到点上
int inc[maxn],cv[maxn],cw[maxn],cn; //inc标记是否在环上,cv存环上的点，cw存点权
double d[maxn],A[maxn],B[maxn],C[maxn],D[maxn];//d存深度，从叶节点开始往上走，
            //A存前缀中链的长度+节点的深度的最大， B存前缀中两个树的深度+两个节点之间距离的最大 cd是后缀
double ans1,ans2=1e18;
void add(int a,int b,int c)
{
	to[idx]=b; ww[idx]=c; ne[idx]=h[a];
	h[a]=idx++;
}
int find(int u)//找环
{
	vis[u]=1;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int v=to[i];
		if(v!=fa[u])
		{
			fa[v]=u; w[v]=ww[i];
			if(vis[v]==0)
			{
				if(find(v)) return 1;
			}
			else //找到环了 回溯
			{
				int p=u;
				while(1)
				{
					inc[p]=1; cv[++cn]=p;
					cw[cn]=w[p]; p=fa[p];
					if(p==u) break;
				}
				return 1;
			}
		}
	}
	return 0;
}
void dfs(int u,int fa)
{
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int v=to[i],w=ww[i];
		if(inc[v]==0 && v!=fa)//不是父节点并且不在环里
		{
			dfs(v,u);//回的时候更新
			ans1=max(ans1,d[u]+d[v]+w); //ans1是子树的直径最大值,此时d[u]还没更新，和d[v]表示的不是同一条，可以加起来
			d[u]=max(d[u],d[v]+w);
		}
	}
}
signed main()
{
	jiasu;
	int n; cin>>n;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n;i++)
	{
		int a,b,c; cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	find(1);//找环， 编号
	for(int i=1;i<=cn;i++)
	 dfs(cv[i],0); //求深度 找 ans1
	double sum=0,mx=0;
	for(int i=1;i<=cn;i++)//求前缀
	{
		sum+=cw[i-1];//sum就是链长的前缀和
		A[i]=max(A[i-1],sum+d[cv[i]]);
		B[i]=max(B[i-1],mx+d[cv[i]]+sum);
		mx=max(mx,d[cv[i]]-sum);
	}
	sum=mx=0;
	double cn_1=cw[cn];cw[cn]=0;//断掉cn-1这条线
	for(int i=cn;i>=1;i--)//求后缀
	{
		sum+=cw[i];//第一个是0
		C[i]=max(C[i+1],sum+d[cv[i]]);
		D[i]=max(D[i+1],mx+d[cv[i]]+sum);
		mx=max(mx,d[cv[i]]-sum);
	}
	double res;
	for(int i=1;i<cn;i++)//拼凑答案 这里i表示断i-i+1这条边
	{
		res=max(max(B[i],D[i+1]),A[i]+C[i+1]+cn_1);
		ans2=min(ans2,res);
	}
	ans2=min(ans2,B[cn]);//断最后一条边
	cout<<fixed<<setprecision(1)<<max(ans1,ans2)/2<<endl;
	return 0;
}