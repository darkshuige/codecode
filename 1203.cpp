#include<bits/stdc++.h>
using namespace std;
int q[50005],t[50000],n;
long long res;
void merge_sort(int l,int r)
{
	if(l>=r) return;
	int mid=l+r>>1;
	merge_sort(l,mid),merge_sort(mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid && j<=r)
	{
		if(q[i]<q[j])
		{
			t[k++]=q[i++];
		}
		else
		{
			t[k++]=q[j++];
			res+=mid-i+1;
		}
	}
	while(i<=mid) t[k++]=q[i++];
	while(j<=r) t[k++]=q[j++];
	for(i=l,j=0;i<=r;i++,j++) q[i]=t[j];
}
int main()
{
	int n;
	while(cin>>n)
	{
		res=0;
		int i;
		for(i=0;i<n;i++)
		{
			cin>>q[i];
		}
		merge_sort(0,n-1);
		cout<<res<<endl;
	}
	return 0;
} 
