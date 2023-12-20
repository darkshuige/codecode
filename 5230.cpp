#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		double a[55][55]={0};
		double h[55]={0};
		double l[55]={0};
		for(int i=0;i<n;i++)
		{
			double sum=0;
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
				sum+=a[i][j];
			}
			h[i]=sum/m;
		}
		for(int j=0;j<m;j++)
		{
			double sum=0;
			for(int i=0;i<n;i++)
			{
				sum+=a[i][j];
			}
			l[j]=sum/n;
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			int flag=1;
			for(int j=0;j<m;j++)
			{
				if(a[i][j]<l[j])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			 count++;
		}
		for(int i=0;i<n;i++)
		{
			if(i!=0)
			 cout<<" ";
			printf("%.2f",h[i]);
		}
		cout<<endl;
		for(int j=0;j<m;j++)
		{
			if(j!=0)
			 cout<<" ";
			printf("%.2f",l[j]);
		}
		cout<<endl;
		cout<<count<<endl;
		cout<<endl;
	}
	return 0;
} 
