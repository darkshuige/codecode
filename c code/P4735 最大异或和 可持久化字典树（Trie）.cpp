#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define lc(x) tr[x].l
#define rc(x) tr[x].r
using namespace std;
const int maxn=600010;
const int len=23;
int n,m,s[maxn];//前缀和
int ch[maxn*25][2],ver[maxn*25];//树，每个点的版本
int root[maxn],idx;//每个版本的跟
void insert(int x,int y,int i)//当前版本，前一个版本，要插入的第几个数
{
	ver[x]=i;
	for(int k=len;k>=0;k--)
	{
		int c=s[i]>>k & 1;
		ch[x][!c]=ch[y][!c];//不同的才走前面
		ch[x][c]=++idx;
		x=ch[x][c]; y=ch[y][c];//双指针都往下走
		ver[x]=i;
	}
}
int query(int x,int L,int v)
{
	int res=0;
	for(int k=len;k>=0;k--)
	{
		int c=v>>k & 1;
		if(ver[ch[x][!c]]>=L)
		 x=ch[x][!c],res+=1<<k;
		else
		 x=ch[x][c];
	}
	return res;
}
signed main()
{
	jiasu;
	ver[0]=-1;
	root[0]=++idx;
	insert(root[0],0,0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		s[i]=s[i-1]^x;
		root[i]=idx++;
		insert(root[i],root[i-1],i);
	}
	while(m--)
	{
		char op; cin>>op;
		if(op=='A')
		{
			int x; cin>>x;
			root[++n]=++idx;
			s[n]=s[n-1]^x;
			insert(root[n],root[n-1],n);
		}
		else
		{
			int l,r,x; cin>>l>>r>>x;
			cout<<query(root[r-1],l-1,s[n]^x)<<endl;
		}
	}
	return 0;
}
