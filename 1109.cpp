#include<stdio.h>
#include<math.h>
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int a[1005]={0};
		int i,dis,cut,max=0;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&dis,&cut);
			a[dis]=cut;
			if(dis>max)
			 max=dis;
		}
		int j=0,k;
		while(a[j]==0)
		 j++;
		int min=1e9+5;
		int pos=j;
		for(j;j<=max;j++)
		{
			int sum=0;
			for(k=pos;k<=max;k++)
			{
				sum+=abs(k-j)*a[k];
			}
			if(sum<min)
			 min=sum;
		}
		printf("%d\n",min);
	}
	return 0;
}
