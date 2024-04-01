#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000010;
int a[maxn],cnt=0;
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
	if(u!=v)
	{
		swap(a[u],a[v]);
		down(v);
	}
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>x;
			a[++cnt]=x;
			up(cnt);
		}
		else if(op==2)
		{
			cout<<a[1]<<endl;
		}
		else
		{
			a[1]=a[cnt--];
			down(1);
		}
	}
	return 0;
}
