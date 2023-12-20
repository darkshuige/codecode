#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=25;
bool vis[maxn];
int n,k,ans,a[maxn];
void work1()
{
	int sum=-1;
	for(int j=0;j<n;j++)
	 if(vis[j])
	 {
	 	if(sum==-1)
	 	 sum=a[j];
	 	else
	 	 sum&=a[j];
	 }
	if(__builtin_popcountll(sum)==k)
	 ans++;
}
void work(int sta)
{
	memset(vis,0,sizeof vis);
	for(int i=0;i<n;i++)
	 if(sta&(1<<i))
	  vis[i]=1;
	work1();
}
signed main()
{
	jiasu;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	for(int sta=1;sta<(1<<n);sta++)
	 work(sta);
	cout<<ans<<endl;
	return 0;
}
