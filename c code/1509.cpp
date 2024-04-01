#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[105]={0},b[105]={0},c[300]={0};
	int a1=0,b1=0;
	int x;
	cin>>x;
	while(x!=-1)
	{
		a[a1++]=x;
		cin>>x;
	}
	cin>>x;
	while(x!=-1)
	{
		b[b1++]=x;
		cin>>x;
	}
	int k=0;
	for(int i=0;i<a1;i++)
	{
		c[k++]=a[i];
	}
	for(int i=0;i<b1;i++)
	{
		c[k++]=b[i];
	}
	sort(c,c+k);
	for(int i=0;i<k;i++)
	{
		if(i!=0)
		 cout<<" ";
		cout<<c[i];
	}
	cout<<endl;
	return 0;
} 
