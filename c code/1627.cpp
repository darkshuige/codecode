#include<bits/stdc++.h>
using namespace std;
int a[1000005]={0};
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=0;i<m;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int ans=(*max_element(a+l,a+r+1))-(*min_element(a+l,a+r+1));
		printf("%d\n",ans);
	}
	return 0;
}
