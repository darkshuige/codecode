#include<bits/stdc++.h>
using namespace std;
int cz(int a[],int x,int n)
{
	int l=1,r=n;
	int mid=(l+r)>>1;
	while(l<=r)
	{
		if(a[mid]>x)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
		mid=(l+r)>>1;
	}
	return r;
}
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int a[100005];
		for(int i=1;i<=n;i++)
		 scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=0;i<m;i++)
		{
			int k;
			scanf("%d",&k);
			int as=cz(a,k,n);
			printf("%d\n",as);
		}
	}
	return 0;
}
