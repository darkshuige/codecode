#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
int a[maxn];
signed main()
{
	jiasu;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>x;
			a[++n]=x;
			sort(a+1,a+1+n);
		}
		else
		{
			if(n<k)
			 cout<<-1<<endl;
			else
			 cout<<a[k]<<endl;
		}
	}
	return 0;
} 
