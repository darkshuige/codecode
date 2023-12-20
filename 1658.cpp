#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	while(cin>>n>>q)
	{
		int a[100005]={0},b[100005]={0};
		for(int i=0;i<n;i++)
		 scanf("%d",&a[i]);
		b[0]=0;
		for(int i=1;i<=n;i++)
		{
			b[i]=b[i-1]+a[i-1];
		}
		for(int i=0;i<q;i++)
		{
			int l,r;
			scanf("%d %d",&l,&r);
			int as;
			as=(b[r]-b[l-1])/(r-l+1);
			printf("%d\n",as);
		}
	}
	return 0;
}
