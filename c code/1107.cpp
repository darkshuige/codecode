#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int a[100005]={0},b[100005]={0};
	int n,m,l,r;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		b[1]=a[0];
		for(i=2;i<=n;i++)
		{
			b[i]=b[i-1]+a[i-1];
		}
		for(i=0;i<m;i++)
		{
			cin>>l>>r;
			cout<<b[l]+b[n]-b[r]<<endl;
		}
	} 
	return 0;
}
