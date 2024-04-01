#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
int a[maxn][maxn];
long long sum[maxn][maxn];
int sum1[maxn]={0},sum2[maxn]={0};
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			sum1[i]+=a[i][j];	
			sum2[j]+=a[i][j];
		}
	}
	long long mm=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sum[i][j]=sum1[i]+sum2[j]-a[i][j];
			mm=max(sum[i][j],mm);
		}
	}
	printf("%lld\n",mm);
    return 0;
}
