#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
map<int,int>m1,m2;
int f1=0,f2=0;
void dfs(int a,int b,int k)
{
	if(b==1)
	{
		f2=1;
		if(a==1) f1=1;
	}
	if(k==1 || (f1==1 && f2==1)) return ;
	if(a%k==0) dfs(a/k,b,k-1);
	if(b%k==0) dfs(a,b/k,k-1);
	dfs(a,b,k-1);
}
signed main()
{
	int a,b;
	while(cin>>a>>b)
	{
		f1=0,f2=0;
		if(a<b) swap(a,b);
		dfs(a,b,100);
		if(f1==0 && f2==1)
		 cout<<b<<endl;
		else
		 cout<<a<<endl;
	}
	return 0;
} 
