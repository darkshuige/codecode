#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 2e9
using namespace std;
const int maxn=100005;
int h[maxn],to[maxn*2],ne[maxn*2],w[maxn*2],idx;
int n,m,in[maxn],k[maxn];
double f[maxn];
void add(int a,int b,int c)
{
	to[idx]=b; w[idx]=c;
	ne[idx]=h[a]; h[a]=idx++;
}
void topu(int u)
{
	queue<int>q; q.push(u);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=h[u];i!=0;i=ne[i])
		{
			int v=to[i];
			f[v]+=(f[u]+w[i])*1.0/k[v];
			if(--in[v]==0) q.push(v);
		}
	}
}
signed main()
{
	jiasu;
	cin>>n>>m;
	idx=1;memset(h,0,sizeof h);
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(b,a,c);
		in[a]++; k[a]++;
	}
	f[n]=0;
	topu(n);
	cout<<fixed<<setprecision(2)<<f[1]<<endl;
	return 0;
} 
