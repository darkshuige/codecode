#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn],c[maxn],d[maxn];
signed main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		d[i]=c[i];
	} 
	int flag=1,temp;
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			temp=a[i];
			int j;
			for(j=i-1;j>=0 && temp<a[j];j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]=temp;
		}
		int ff=1;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=c[i]) ff=0;
		}
		if(ff) flag=0;
	}
	if(flag==0)
	{
		cout<<"Insertion Sort"<<endl;
		int pos=1;
		while(c[pos]>c[pos-1])
		 pos++;
		temp=c[pos];
		int j;
		for(j=pos-1;j>=0 && temp<c[j];j--)
		 c[j+1]=c[j];
		c[j+1]=temp;
		for(int i=0;i<n;i++)
		{
			if(i!=0) cout<<" ";
			cout<<c[i];
		}
		cout<<endl;
	} 
	else
	{
		cout<<"Heap Sort"<<endl;
		int i=n-1;
		while(d[i]>=d[0]) i--;
		swap(d[0],d[i]);
		int root=0,son=root*2+1;
		while(son<i)
		{
			if(son+1<i && d[son+1]>d[son])
			 son++;
			if(d[son]>d[root])
			{
				swap(d[son],d[root]);
				root=son;
				son=root*2+1;
			}
			else
			 break;
		}
		for(int i=0;i<n;i++)
		{
			if(i!=0) cout<<" ";
			cout<<d[i];
		}
		cout<<endl;
	}
	return 0;
}