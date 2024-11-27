#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2005;
int a[maxn];
int b[maxn];
int ti[maxn];
queue<int>q[25];
signed main()
{
	jiasu;
	int n,m,k,qq; cin>>n>>m>>k>>qq;
	for(int i=1;i<=k;i++) cin>>b[i];
	for(int i=1;i<=n*m;i++)
	{
		int kk=(i-1)%n+1;
		a[kk]+=b[i]; ti[i]=a[kk];
		q[kk].push(a[kk]);
	}
	for(int i=n*m+1;i<=k;i++)
	{
		int pos=1;
		for(int j=1;j<=n;j++)
		 if(q[j].front()<q[pos].front()) pos=j;
		a[pos]+=b[i]; ti[i]=a[pos];
		q[pos].pop();
		q[pos].push(ti[i]);
	}
	while(qq--)
	{
		int an; cin>>an;
		int h=8,mi=0;
		mi+=ti[an];
		h+=mi/60; mi%=60;
		if((ti[an]-b[an]>=540))
		 cout<<"Sorry"<<endl;
		else
		 cout<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<mi<<endl;
	}
	return 0;
} 