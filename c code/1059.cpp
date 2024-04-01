#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int cmp(const int a,const int b)
{
	return a>b;
}
int main()
{
	int n,j;
	while(scanf("%d",&n)!=EOF)
	{
		int sum=0;
		int a[1005]={0},b[1005]={0};
		int i,l1,l2;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		l1=n-1,l2=n-1,i=0,j=0;
		while(i<=l1 && j<=l2)
		{
			if(a[l1]>b[l2])
			{
				sum++;
				l1--;
				l2--;
			}
			else if(a[i]>b[j])
			{
				sum++;
				i++;
				j++;
			}
			else
			{
				if(a[l1]!=b[j])
				{
					sum--;
				}
				l1--;
				j++;
			}
		}
		cout<<200*sum<<endl;
	}
	return 0;
}
