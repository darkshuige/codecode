#include<bits/stdc++.h>
using namespace std;
int a[3000005];
int b[3000005];
void merge_sort(int l,int mid,int r)//¹é²¢ 
{
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=r)
	{
		if(a[i]<a[j])
		 b[k++]=a[i++];
		else
		 b[k++]=a[j++];
	}
	while(i<=mid)
	 b[k++]=a[i++];
	while(j<=r)
	 b[k++]=a[j++];
	for(i=l;i<=r;i++)
	 a[i]=b[i];
}
void ff(int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)>>1;
		ff(l,mid);
		ff(mid+1,r);
		merge_sort(l,mid,r);	
	}
}
int main()
{
	int n;
	scanf("%d",&n); 
	for(int i=0;i<n;i++)
	 scanf("%d",&a[i]);
	ff(0,n-1);
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		 printf(" ");
		printf("%d",a[i]);
	}		
	printf("\n");
}
