#include<bits/stdc++.h>
using namespace std;
int res=0,n,m=3;
int dfs(int i,int j)
{
	if(j==m) return 0;
	if(i==n)
	{
		res++;
		return 1;
	}
	dfs(i+1,0);
	dfs(i+1,j+1);
}
int main()
{
	while(cin>>n)
	{
		res=0;
		dfs(0,0);
		cout<<res<<endl;
	}
	return 0;
} 
