#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		map<int,int>sb;
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			sb[a]++;
		}
		for(int i=0;i<m;i++)
		{
			int a;
			scanf("%d",&a);
			if(sb[a])
			 printf("YES\n");
			else
			 printf("NO\n");
		}	
	}
	
	return 0;
}
