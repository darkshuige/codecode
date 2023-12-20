#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		int a[305]={0},count=0,max=0,b[305]={0},j;
		if(a[i])
		 b[0]=1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==0)
			 count++;
		}
		for(i=0;i<n;i++)
		{
			if(a[i])
			 b[i]=1; 
			for(j=0;j<i;j++)
			{
				if(a[j] && a[j]<a[i] && b[j]>=b[i])
				{
					b[i]=b[j]+1;
				}
			}
		}
		sort(b,b+n);
		cout<<b[n-1]+count<<endl;
	}
	return 0;
} 
