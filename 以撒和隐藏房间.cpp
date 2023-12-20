#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=1005;
char a[maxn][maxn];
int n,m;
int check(int i,int j)
{
	if(a[i][j]=='0')
	{
		int sum=0;
		if(i-1>=0)
		{
			if(a[i-1][j]=='2')
			 return 0;
			else if(a[i-1][j]=='1')
			 sum++;	
		}
		if(i+1<n)
		{
			if(a[i+1][j]=='2')
			 return 0;
			else if(a[i+1][j]=='1')
			 sum++;	
		}
		if(j-1>=0)
		{
			if(a[i][j-1]=='2')
			 return 0;
			else if(a[i][j-1]=='1')
			 sum++;
		}
		if(j+1>=0)
		{
			if(a[i][j+1]=='2')
			 return 0;
			else if(a[i][j+1]=='1')
			 sum++;
		}
		if(sum==3)
		 return 1;
		else
		 return 0;
	}
	else
	 return 0;
}
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++)
	  cin>>a[i][j];
	int cnt=0;
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++)
	 {
	 	if(check(i,j))
	 	 cnt++;
	 }
	if(cnt>0)
	 cout<<"YES"<<endl<<cnt<<endl;
	else
	 cout<<"NO"<<endl;
	return 0;
} 
