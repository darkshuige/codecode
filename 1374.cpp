#include<bits/stdc++.h>
using namespace std;
int dfs(int n)
{
	if(n<=2)
	 return 0;
	if(n%2==0)
	{
		return 2*dfs(n/2);
	}
	else
	{
		return dfs(n/2)+dfs(n/2+1)+1;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",dfs(n));
	}
	return 0;
}
