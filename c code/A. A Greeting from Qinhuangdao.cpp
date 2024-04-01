#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=220;
char a[maxn][maxn];
int ex[]={-1,+0,+1,-1};
int ey[]={+0,+1,+0,-1};
int gcd(int a,int b)
{
	if(a<b) swap(a,b);
	int t=a%b;
	while(t)
	{
		a=b;
		b=t;
		t=a%b;
	}
	return b;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int r,b;
		cin>>r>>b;
		cout<<"Case #"<<i<<": ";
		if(r<=1)
		{
			cout<<"0/1"<<endl;
			continue;
		}
		else if(r>=2 && b==0)
		{
			cout<<"1/1"<<endl;
			continue;
		}
		int fz=r*(r-1);
		int fm=(r+b)*(r+b-1);
		int g=gcd(fz,fm);
		fz/=g;
		fm/=g;
		cout<<fz<<"/"<<fm<<endl;
	}
	return 0;
}
