#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
const int maxn=100005;
const int mod=10007;
struct node
{
	int l,r,lazy[5],v[5];
}tr[maxn<<4];
void pushup(int p)
{
	tr[p].v[1]=(tr[lc].v[1]+tr[rc].v[1])%mod;
	tr[p].v[2]=(tr[lc].v[2]+tr[rc].v[2])%mod;
	tr[p].v[3]=(tr[lc].v[3]+tr[rc].v[3])%mod;
}
void build(int p,int x,int y)
{
	tr[p].l=x,tr[p].r=y,tr[p].lazy[1]=0,tr[p].lazy[2]=1,tr[p].lazy[3]=0,tr[p].v[1]=0,tr[p].v[2]=0,tr[p].v[3]=0;
	if(tr[p].l==tr[p].r) return ;
	int m=tr[p].l+tr[p].r>>1;
	build(lc,x,m);
	build(rc,m+1,y);
	pushup(p);
}
void pushdown(int p)
{
	if(tr[p].lazy[3])//lazy3表示覆盖的lazy 
	{
		tr[lc].lazy[3]=tr[rc].lazy[3]=tr[p].lazy[3];//首先处理子树的lazy
		tr[lc].lazy[1]=0;tr[rc].lazy[1]=0;
		tr[lc].lazy[2]=1;tr[rc].lazy[2]=1;
		
		int len=tr[lc].r-tr[lc].l+1;
		tr[lc].v[1]=tr[p].lazy[3]*len%mod;//处理子树的v 左子树 
		tr[lc].v[2]=tr[p].lazy[3]*tr[p].lazy[3]%mod*len%mod;
		tr[lc].v[3]=tr[p].lazy[3]*tr[p].lazy[3]%mod*tr[p].lazy[3]%mod*len%mod;
		
		len=tr[rc].r-tr[rc].l+1;//右子树 
		tr[rc].v[1]=tr[p].lazy[3]*len%mod;
		tr[rc].v[2]=tr[p].lazy[3]*tr[p].lazy[3]%mod*len%mod;
		tr[rc].v[3]=tr[p].lazy[3]*tr[p].lazy[3]%mod*tr[p].lazy[3]%mod*len%mod;
		tr[p].lazy[3]=0;
	}
	if(tr[p].lazy[2]!=1) //lazy2表示乘法的lazy
	{
		tr[lc].lazy[2]=tr[lc].lazy[2]*tr[p].lazy[2]%mod;//处理左子树lazy2
		tr[lc].lazy[1]=tr[lc].lazy[1]*tr[p].lazy[2]%mod;//处理左子树lazy1
		
		tr[rc].lazy[2]=tr[rc].lazy[2]*tr[p].lazy[2]%mod;//处理右子树lazy2
		tr[rc].lazy[1]=tr[rc].lazy[1]*tr[p].lazy[2]%mod;//处理右子树lazy1
		
		tr[lc].v[1]=tr[lc].v[1]*tr[p].lazy[2]%mod;//处理左子树v
		tr[lc].v[2]=tr[lc].v[2]*tr[p].lazy[2]%mod*tr[p].lazy[2]%mod;
		tr[lc].v[3]=tr[lc].v[3]*tr[p].lazy[2]%mod*tr[p].lazy[2]%mod*tr[p].lazy[2]%mod;
		
		tr[rc].v[1]=tr[rc].v[1]*tr[p].lazy[2]%mod;//处理右子树v
		tr[rc].v[2]=tr[rc].v[2]*tr[p].lazy[2]%mod*tr[p].lazy[2]%mod;
		tr[rc].v[3]=tr[rc].v[3]*tr[p].lazy[2]%mod*tr[p].lazy[2]%mod*tr[p].lazy[2]%mod;
		tr[p].lazy[2]=1;
	}
	if(tr[p].lazy[1])//lazy1表示加法的lazy 
	{
		tr[lc].lazy[1]=(tr[lc].lazy[1]+tr[p].lazy[1])%mod;//还是先算lazy 
		tr[rc].lazy[1]=(tr[rc].lazy[1]+tr[p].lazy[1])%mod;
		
		int len=tr[lc].r-tr[lc].l+1;//算左子树的v
		tr[lc].v[3]=(tr[lc].v[3]+3*tr[lc].v[2]%mod*tr[p].lazy[1]%mod)%mod;//(a+b)^3=a^3+b^3+3a^2b+3ab^2
		tr[lc].v[3]=(tr[lc].v[3]+3*tr[lc].v[1]%mod*tr[p].lazy[1]%mod*tr[p].lazy[1]%mod)%mod;
		tr[lc].v[3]=(tr[lc].v[3]+len*tr[p].lazy[1]%mod*tr[p].lazy[1]%mod*tr[p].lazy[1]%mod)%mod;
		
		tr[lc].v[2]=(tr[lc].v[2]+2*tr[lc].v[1]%mod*tr[p].lazy[1]%mod)%mod;// (a+b)^2=a^2+2ab+b^2
		tr[lc].v[2]=(tr[lc].v[2]+len*tr[p].lazy[1]%mod*tr[p].lazy[1]%mod)%mod;
		
		tr[lc].v[1]=(tr[lc].v[1]+len*tr[p].lazy[1]%mod)%mod;
		
		len=tr[rc].r-tr[rc].l+1;
		tr[rc].v[3]=(tr[rc].v[3]+3*tr[rc].v[2]%mod*tr[p].lazy[1]%mod)%mod;//(a+b)^3=a^3+b^3+3a^2b+3ab^2
		tr[rc].v[3]=(tr[rc].v[3]+3*tr[rc].v[1]%mod*tr[p].lazy[1]%mod*tr[p].lazy[1]%mod)%mod;
		tr[rc].v[3]=(tr[rc].v[3]+len*tr[p].lazy[1]%mod*tr[p].lazy[1]%mod*tr[p].lazy[1]%mod)%mod;
		
		tr[rc].v[2]=(tr[rc].v[2]+2*tr[rc].v[1]%mod*tr[p].lazy[1]%mod)%mod;// (a+b)^2=a^2+2ab+b^2
		tr[rc].v[2]=(tr[rc].v[2]+len*tr[p].lazy[1]%mod*tr[p].lazy[1]%mod)%mod;
		
		tr[rc].v[1]=(tr[rc].v[1]+len*tr[p].lazy[1]%mod)%mod;
		
		tr[p].lazy[1]=0;
	}
}
void update(int p,int x,int y,int op,int c)
{
	if(x<=tr[p].l && y>=tr[p].r)//如果全部包含 
	{
		int len=tr[p].r-tr[p].l+1;
		if(op==1)
		{
			tr[p].lazy[1]=(tr[p].lazy[1]+c)%mod;
			
			tr[p].v[3]=(tr[p].v[3]+3*tr[p].v[2]%mod*c%mod)%mod;//(a+b)^3=a^3+b^3+3a^2b+3ab^2
			tr[p].v[3]=(tr[p].v[3]+3*tr[p].v[1]%mod*c%mod*c%mod)%mod;
			tr[p].v[3]=(tr[p].v[3]+len*c%mod*c%mod*c%mod)%mod;
			
			tr[p].v[2]=(tr[p].v[2]+2*tr[p].v[1]%mod*c%mod)%mod;// (a+b)^2=a^2+2ab+b^2
			tr[p].v[2]=(tr[p].v[2]+len*c%mod*c%mod)%mod;
			
			tr[p].v[1]=(tr[p].v[1]+len*c%mod)%mod;
		}
		else if(op==2)
		{
			tr[p].lazy[2]=tr[p].lazy[2]*c%mod;
			tr[p].lazy[1]=tr[p].lazy[1]*c%mod;
			
			tr[p].v[1]=tr[p].v[1]*c%mod;
			tr[p].v[2]=tr[p].v[2]*c%mod*c%mod;
			tr[p].v[3]=tr[p].v[3]*c%mod*c%mod*c%mod;
		}
		else if(op==3)
		{
			tr[p].lazy[3]=c;tr[p].lazy[1]=0;tr[p].lazy[2]=1;
			tr[p].v[1]=len*c%mod;
			tr[p].v[2]=len*c%mod*c%mod;
			tr[p].v[3]=len*c%mod*c%mod*c%mod;
		}
		return ;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y,op,c);
	if(y>m) update(rc,x,y,op,c);
	pushup(p);
}
int query(int p,int x,int y,int op)
{
	if(x<=tr[p].l && y>=tr[p].r)
	{
		return tr[p].v[op];
	}
	int m=tr[p].l+tr[p].r>>1;
	int sum=0;
	if(x<=m) sum=(sum+query(lc,x,y,op))%mod;
	if(y>m) sum=(sum+query(rc,x,y,op))%mod;
	return sum;
}
signed main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0) break;
		build(1,1,n);
		while(m--)
		{
			int op,a,b,c;
			cin>>op>>a>>b>>c;
			if(op==4)
			 cout<<query(1,a,b,c)<<endl;
			else
			 update(1,a,b,op,c);
		}
	}
	return 0;
}
