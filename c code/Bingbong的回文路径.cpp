#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
const int M=998244853;
const int maxn=200050;
int n,m,t,dep[maxn],fa[maxn][20],p,k;
int pw[maxn],h1[maxn],h2[maxn];
string s;
int lca(int x,int y)
{
	if(dep[x]>dep[y])swap(x,y);
    for(int i=18;i>=0;i--)if(dep[fa[y][i]]>=dep[x])y=fa[y][i];
    if(x==y)return x;
    for(int i=18;i>=0;i--)if(fa[x][i]!=fa[y][i])
	{
        x=fa[x][i]; y=fa[y][i];
    }
    return fa[x][0];
}
int fk(int x,int y)
{
	return ((h2[x]-h2[p]+M)+(h1[y]-h1[fa[p][0]]+M)*pw[maxn-dep[p]*2])%M*pw[dep[x]]%M;
}
signed main()
{
	jiasu; pw[0]=1;
	for(int i=1;i<maxn;i++) pw[i]=pw[i-1]*114514%M;//计算pow
	cin>>n>>s;  s="$"+s;
	for(int i=1;i<=n;i++)
	{
		cin>>k;//父节点
		fa[i][0]=k; dep[i]=dep[k]+1;
		for(int j=1;j<=18;j++)
		 fa[i][j]=fa[fa[i][j-1]][j-1];//倍增
		h1[i]=(h1[k]+pw[dep[i]]*s[i])%M;//子节点更大，自下向上
		h2[i]=(h2[k]+pw[maxn-dep[i]]*s[i])%M;//自上向下
	}
	cin>>t;
	while(t--)
	{
		int a,b; cin>>a>>b;
		p=lca(a,b);
		cout<<(fk(a,b)==fk(b,a)?"YES\n":"NO\n");
	}
	return 0;
}
