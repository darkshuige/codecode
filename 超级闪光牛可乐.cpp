#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
signed main()
{
	jiasu;
	int x,n;
	cin>>x>>n;
	char a; int b=-1;
	for(int i=0;i<n;i++)
	{
		char k; int c;
		cin>>k>>c;
		if(c>b)
		{
			b=c;
			a=k;
		}
	}
	if(1000*b<x)
	{
		cout<<-1<<endl;
	}
	else
	{
		int pos=x/b;
		if(x%b!=0) pos++;
		for(int i=0;i<pos;i++)
		 cout<<a;
		cout<<endl;
	}
	return 0;
} 
