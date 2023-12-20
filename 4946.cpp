#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			int a[105]={0};
			int pos=0;
			int maxn=INT_MIN;
			int sum=0;
			for(int j=0;j<m;j++)
			{
				cin>>a[j];
				sum+=a[j];
				if(a[j]>maxn)
				{
					maxn=a[j];
					pos=j;
				}
			}
			for(int j=0;j<m;j++)
			{
				if(j!=0)
				 cout<<" ";
				if(j==pos)
				 cout<<sum;
				else
				 cout<<a[j];
			}
			cout<<endl;
		}
	}
	return 0;
} 
