#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
char a[6][maxn];
int s[6];
signed main()
{
	int n,h; cin>>n>>h;
	int s1=0,s2=0,s3=0;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[2][i]=='*')
		{
			s1++;
			if(a[1][i]=='*')
			 s2++;
		}
		else if(a[2][i]=='#' && a[1][i]=='*')
		 s3++;
		
		if(a[4][i]=='*')
		{
			s1++;
			if(a[5][i]=='*')
			 s2++;
		}
		else if(a[4][i]=='#' && a[5][i]=='*')
		 s3++;
	}
	int sum=0;
	if(h>=s1)
	{
		h-=s1;
		sum+=s1;
	}
	else
	{
		sum+=h;
		h=0;
	}
	
	if(h>=s2)
	{
		h-=s2;
		sum+=s2;
	}
	else
	{
		sum+=h;
		h=0;
	}
	
	if(h>=s3*2)
	{
		h-=s3*2;
		sum+=s3;
	}
	else
	{
		sum+=h/2;
		h=0;
	}
	cout<<sum<<endl;
	return 0;
}