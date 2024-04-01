#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=210;
int f[maxn][maxn];//存各个点的mex值
int sg(int n,int m)
{
	if(f[n][m]!=-1)
	 return f[n][m];
	set<int>st;
	for(int i=2;i<=n-2;i++)
	 st.insert(sg(i,m)^sg(n-i,m));
	for(int i=2;i<=m-2;i++)
	 st.insert(sg(n,i)^sg(n,m-i));
	for(int i=0;;i++)
	 if(!st.count(i))
	  return f[n][m]=f[m][n]=i;
} 
signed main()
{
	int n,m;
	memset(f,-1,sizeof f);
	while(cin>>n>>m)
	{
		if(sg(n,m))
		 cout<<"WIN"<<endl;
		else 
		 cout<<"LOSE"<<endl;
	}
	return 0;
}
