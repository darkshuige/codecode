#include<iostream>
#include<stdio.h>
using namespace std;
int a[100005]={0},b[100005]={0};
int cnt=0;
void merge_sort(int l,int r){
    if(r>l){
        int mid=(r+l)/2;
        int i=l;
        int p=l,q=mid+1;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        while(p<=mid||q<=r)
		{
            if(q>r||(p<=mid&&a[p]<=a[q]))
			{
                b[i++]=a[p++];
            }
			else
			{
                b[i++]=a[q++];
                cnt+=mid-p+1;
            }
        }
        for(i=l;i<=r;i++)
		{
            a[i]=b[i];
        }
    }      
}
int main()
{
	int n,m;
	int i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		a[i]=i;
	}
	for(i=0;i<m;i++)
	{
		cnt=0;
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);
		int j,t;
		k=k%(r-l+1);
		while(k--)	
		{
			t=a[r];
			for(j=r;j>=l+1;j--)
			{
				a[j]=a[j-1];
			}
			a[l]=t;	
		}
		int c[100005]={0};
		for(k=1;k<=n;k++)
		  c[k]=a[k];
		merge_sort(1,n);
		for(k=1;k<=n;k++)
		  a[k]=c[k];
		if(cnt%2==0)
		{
			printf("hao\n");
		}
		else
		{
			printf("huai\n");
		}
	}
	return 0;
}
