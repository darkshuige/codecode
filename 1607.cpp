#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1) break;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			for(int j=1;j<=i;j++)
			{
				if(a[i]<a[j])
				{
					b[i]++;
				}
			}
		}
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			int k;
			scanf("%d",&k);
			printf("%d\n",b[k]);
		}
	}
	return 0;	
}
