#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100010;
int a[maxn],cnt;
void up(int u)
{
	if(u/2 && a[u/2]>a[u])
	{
		swap(a[u],a[u/2]);
		up(u/2);
	}
}
void down(int u)
{
	int v=u;
	if(u*2<=cnt && a[u*2]<a[v])
	 v=u*2;
	if(u*2+1<=cnt && a[u*2+1]<a[v])
	 v=u*2+1;
	if(v!=u)
	{
		swap(a[v],a[u]);
		down(v);
	}
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	cnt=0;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		a[++cnt]=op;
		up(cnt);
	}
	int sum=0;
	while(sum<n)
	{
		if(sum!=0)
		 cout<<" ";
		cout<<a[1];
		a[1]=a[cnt--];
		sum++;
		down(1); 
	}
	cout<<endl;
	return 0;
}
