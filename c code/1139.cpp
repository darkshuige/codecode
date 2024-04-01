#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstring> 
int a[100005]={0};
bool b[100005]={0};
using namespace std;
int cmp(const int a,const int b)
{
	return a<b;
}
int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		memset(b,0,sizeof(b));
		int i;
		for(i=0;i<n;i++)
		 scanf("%d",&a[i]);
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
		{
			if(a[i]>m)
			{
				m+=2;
				b[i]=1;		
			}
		} 
		for(i=0;i<n;i++)
		{
			if(b[i]==0)
			 m++;	
		}
		printf("%d\n",m);
	}
	return 0;
}
