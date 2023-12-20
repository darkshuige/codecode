#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=305;
int dp[maxn][2];
signed main()
{
	jiasu;
	int t;
	int n;
	int a[]={1,2,3,4};
	do
	{
		for(int i=0;i<4;i++)
		 cout<<a[i];
		cout<<endl;
	}while(next_permutation(a,a+4));
	return 0;
}
