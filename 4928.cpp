#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
void dfs(long long a)
{
	if(a<=m)
	{
		cnt++;
		dfs(a*2);
		dfs(a*2+1);	
	}
}
int main()
{
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
		 break;
		cnt=0;
		dfs(n);
		cout<<cnt<<endl;
	}
	return 0;
} 
