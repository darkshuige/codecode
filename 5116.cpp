#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,op,m;
	int a[100005]={0};
	int c[100005]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	scanf("%d",&m);
	sort(c+1,c+1+n);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&op);
		int pos=upper_bound(c+1,c+1+n,a[op])-c;
		printf("%d\n",n-pos+1);
	}
	return 0;
}
