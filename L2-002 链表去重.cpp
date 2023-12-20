#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],check[100005],res1[100005],res2[100005];
int main()
{
	int n,t,i;
	int num;
	int l1=0,l2=0;
	cin>>num>>n;
	for(i=0;i<n;i++)
	{
		cin>>t;
		cin>>a[t]>>b[t];
	}
	while(num!=-1)
	{
		if(check[abs(a[num])]==0)
		{
			check[abs(a[num])]++;
			res1[l1++]=num;	
		}
		else
		{
			res2[l2++]=num;
		}
		num=b[num];
	}
	for(i=0;i<l1-1;i++)
	{
		num=res1[i];
		printf("%05d %d %05d\n",num,a[num],res1[i+1]);
	}
	num=res1[i];
	printf("%05d %d -1\n",num,a[num]);
	if(l2)
	{
		for(i=0;i<l2-1;i++)
		{
			num=res2[i];
			printf("%05d %d %05d\n",num,a[num],res2[i+1]);
		}
		num=res2[i];
		printf("%05d %d -1\n",num,a[num]);
	}
	return 0;
}
