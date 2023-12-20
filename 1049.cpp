#include<iostream>
#include<stdio.h>
#include<algorithm>
int cmp(const int a,const int b)
{
	return a>b;
}
using namespace std;
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		int a[105]={0},count=1,sum=1;
		for(i=0;i<n;i++)
		 cin>>a[i];
		sort(a,a+n,cmp);
		for(i=1;i<n;i++)
		{
			if(a[i]!=a[i-1])
			 count++;
			if(count==5)
			 break;
		}
		for(i++;;i++)
		{
			if(a[i]==a[i-1])
			 sum++;
			else
			 break;
		}
		cout<<sum<<endl;
	}
	return 0;
}
