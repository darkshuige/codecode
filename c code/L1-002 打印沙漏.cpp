#include<bits/stdc++.h>
using namespace std;
int a[300];
void init()
{
	a[1]=1;
	int k=2;
	for(int i=3;k<50;i+=2)
	{
		a[k]=a[k-1]+2*i;
		k++;
	}
}
int main()
{
	init();
	int n;
	char q;
	cin>>n>>q;
	int i;
	if(n<=0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(i=1;i<50;i++)
	{
		if(a[i]>n)
		 break;
	}
	i--;
	int j,k,l;
	for(k=0;k<(i*2-1)/2+1;k++)//ÉÏ²¿·Ö 
	{
		for(l=0;l<k;l++)
		 cout<<" ";
		for(j=0;j+2*k<i*2-1;j++)
		 cout<<q;
		cout<<endl;
	}
	for(k=1;k<=(i*2-1)/2;k++)
	{
		for(l=(i*2-k*2-2)/2;l>0;l--)
		 cout<<" ";
		for(j=0;j<k*2+1;j++)
		 cout<<q;
		cout<<endl;
	}
	cout<<n-a[i]<<endl;
	return 0;
}
