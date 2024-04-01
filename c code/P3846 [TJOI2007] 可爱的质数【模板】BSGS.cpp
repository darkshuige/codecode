#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
//BSGS算法
//用来计算a^x===b (mod p) 本质分块思想 O(sqrt(p))   a和p互质
const int maxn=200005;
int bsgs(int a,int b,int p)
{
	a%=p,b%=p;
	if(b==1) return 0;
	int m=ceil(sqrt(p));
	int t=b;
	unordered_map<int,int>hash;
	hash[b]=0;
	for(int j=1;j<m;j++)
	{
		t=t*a%p; //求b*a^j
		hash[t]=j;
	}
	int mi=1;
	for(int i=1;i<=m;i++)
	 mi=mi*a%p; //求a^m
	t=1;
	for(int i=1;i<=m;i++)
	{
		t=t*mi%p;   //求(a^m)^i
		if(hash.count(t))
		 return i*m-hash[t];
	}
	return -1;
}
signed main()
{
	jiasu;
	int p,b,a; cin>>p>>a>>b;
	int res=bsgs(a,b,p);
	if(res==-1) cout<<"no solution"<<endl;
	else cout<<res<<endl;
	return 0;
}