#include <stdio.h>
int a[30]={6,6,7,8,10,0,5,0,0,8,3,6,4,5,4,4,3,2,0,10,5,10,10,2,7,4,6,5};
int main()
{
	int n,k;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&k);
		k--;
		printf("%d\n",a[k%28]);
	}
	return 0;
}
