#include<bits/stdc++.h>
using namespace std;
int a[110];
void init()
{
	a[0]=2;
	for(int i=1;i<110;i++)
	{
		a[i]=a[i-1]+2;
	}
}
int main()
{
	init();
	int n,m;
	while(cin>>n>>m)
	{
		int count=0;
		int sum=0;
		int k=0;
		int i=0;
		if(n==0)
		{
			cout<<"0"<<endl;
		}
		else
		{
			while(n)
			{
				if(n>=m)
				{
					for(k=0;k<m;k++)
					{
						sum+=a[i];
						i++;
					}
					if(count!=0)
					{
						cout<<" ";
					}
					cout<<sum/m;
					count++;
					n-=m;
					sum=0;
				}
				else
				{
					for(k=0;k<n;k++)
					{
						sum+=a[i];
						i++;
					}
					if(count!=0)
					{
						cout<<" ";
					}
					cout<<sum/(n);
					count++;
					n=0;
					sum=0;
				}
			}
			cout<<endl;	
		}
		
	}
	return 0;
}
