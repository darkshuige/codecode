#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200005;
__int128 n,x,k;
__int128 ans;
void dfs(int now,int l,int f)
{
	if(l>k) return ;
	if(l==k)
	{
		ans++;
		return ;
	}
	if(now/2>=1 && now/2!=f) dfs(now/2,l+1,now);
	if(now*2<=n && now*2!=f) dfs(now*2,l+1,now);
	if(now*2+1<=n && now*2+1!=f) dfs(now*2+1,l+1,now);
}
void scan(__int128 &x)//ÊäÈë
{
	x=0;int f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
inline void print(__int128 x)
{
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	scan(n),scan(x),scan(k);
    	ans=0;
    	dfs(x,0,0);
    	print(ans);
    	cout<<endl;
	}
    return 0;
}
