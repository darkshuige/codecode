#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100005]={0};
int b[50]={0};
int cmp(const int a,const int b)
{
	return a<b;
}
int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		memset(a,0,sizeof(int));
		memset(b,0,sizeof(int));
		int j;
		for(j=0;j<n;j++)
		 scanf("%d",&a[j]);
		for(j=0;j<m;j++)
		 scanf("%d",&b[j]);
		sort(a,a+n,cmp);
		sort(b,b+m,cmp);
		int k=0,count=0,sum=0;
		j=0;
		while(k<m)
		{
			if(b[k]>1)
			{
				b[k]--;
				count++;
			}
			else if(b[k]==1)
			{
				k++;
				sum+=a[j];
				sum+=count*20;
				count=0;
			}
			j++;
		}
		printf("Case %d: %d\n",i,sum);
	}
	return 0;
}
