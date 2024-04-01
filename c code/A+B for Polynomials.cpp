#include<iostream>
using namespace std;
void px(double d[],int d1[],int n)
{
	int i,max,j;
	double t1;
	int t2;
	for(i=0;i<n;i++)
	{
		max=i;
		for(j=i;j<n;j++)
		{
			if(d1[j]>d1[max])
			{
				max=j;
			}
		}
		t1=d[i];d[i]=d[max];d[max]=t1;
		t2=d1[i];d1[i]=d1[max];d1[max]=t2;
	}
}
int main()
{
	int k1,k2;
	double a[30]={0},b[30]={0};
	int a1[30]={0},b1[30]={0};
	cin>>k1;
	int i;
	for(i=0;i<k1;i++)
	{
		cin>>a1[i];
		cin>>a[i];
		if(a[i]==0)
		{
			i--;
			k1--;
		}
	}
	px(a,a1,k1);
	cin>>k2;
	for(i=0;i<k2;i++)
	{
		cin>>b1[i];
		cin>>b[i];
		if(a[i]==0)
		{
			i--;
			k2--;
		}
	}
	px(b,b1,k2);
	int j=0,count=0;
	i=0;
	while(i<k1 && j<k2)
	{
		if(a1[i]>b1[j])
		{
			count++;
			i++;
		}
		else if(a1[i]<b1[j])
		{
			count++;
			j++;
		}
		else if(a1[i]==b1[j])
		{
			i++;
			j++;
			count++;
		}
	}
	while(i<k1)
	{
		count++;
		i++;
	}
	while(j<k2)
	{
		count++;
		j++;
	}
	cout<<count<<" ";
	i=0,j=0;
	count=0;
	while(i<k1 && j<k2)
	{
		if(count!=0)
		 cout<<" ";
		if(a1[i]>b1[j])
		{
			printf("%d %.1f",a1[i],a[i]);
			i++;
		}
		else if(a1[i]<b1[j])
		{
			printf("%d %.1f",b1[j],b[j]);
			j++;
		}
		else if(a1[i]==b1[j])
		{
			printf("%d %.1f",b1[j],b[j]+a[i]);
			i++;
			j++;
		}
		count++;
	}
	while(i<k1)
	{
		if(count!=0)
		 cout<<" ";
		printf("%d %.1f",a1[i],a[i]);
		i++;
	}
	while(j<k2)
	{
		if(count!=0)
		 cout<<" ";
		printf("%d %.1f",b1[j],b[j]);
		j++;
		count++;
	}
	return 0;
}
