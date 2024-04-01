#include<iostream>
#include<algorithm>
#include<stdio.h>
int cmp(const int a,const int b)
{
	return a<b;
}
using namespace std;
int main()
{
	int n,c;
	while(scanf("%d %d",&n,&c)!=EOF)
	{
		int v[105]={0};
		int i;
		for(i=0;i<n;i++)
		{
			cin>>v[i];
		}
		sort(v,v+n);
		i=0;
		while(i<n)
		{
			c=c-v[i];
			if(c<0)
			 break;
			i++;
		}
		cout<<i<<endl;
	}
	return 0;
}
