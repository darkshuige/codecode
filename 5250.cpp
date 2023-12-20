#include<bits/stdc++.h>
using namespace std;
bool a[100005]={0};
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		if(a[k]==0)
		{
			if(i!=0)
			 printf(" ");
			a[k]=1;
			printf("%d",k);
		}
	}
	printf("\n");
	return 0;
}
