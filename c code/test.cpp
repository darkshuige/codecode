#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=5050;
char ans[maxn][maxn];
signed main()
{
	
	int n1=5,n2=6;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		 ans[i][j]='c';
	}
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		 cout<<ans[i][j];
		cout<<endl;
	}
	return 0;
} 
