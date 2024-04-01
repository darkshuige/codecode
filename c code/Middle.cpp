#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=1000005;
char b[maxn];
int a[maxn];
int f(int x,int a,char b)
{
	if(b=='|')
	 x|=a;
	else if(b=='^')
	 x^=a;
	else if(b=='&')
	 x&=a;
	return x;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	cin>>b+1;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int pos,val;
			cin>>pos>>val;
			a[pos]=val;
		}
		else if(op==2)
		{
			int x,l,r;
			cin>>x>>l>>r;
			for(int i=l;i<=r;i++)
			 x=f(x,a[i],b[i]);
			cout<<x<<endl;
		}
	}
	return 0;
} 
