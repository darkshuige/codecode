#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
	int sum=1;
	for(int i=1;i<=n;i++)
	 sum*=i;
	return sum;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a[105]={0};
		int n;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		 scanf("%d",&a[j]);
		int count=0;
		do
		{
			count++;
		}
		while(next_permutation(a,a+n));
		printf("%d\n",f(n)-count+1);	
	}
	return 0;
}
