#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[1005]={0};
		int i,sum=0;
		for(i=0;i<n;i++)
		 cin>>a[i];
		int k,j;
		sort(a,a+n);
		for(i=n-1;i>=0;i--)
		{
			for(k=0;k<n;k++)
			{
				for(j=0;j<n;j++)
				{
					if(a[i]!=a[k] && a[i]!=a[j] && a[k]!=a[j])
					{
						sum=a[i]-a[k]-a[j];
						if(binary_search(a,a+n,sum) && sum!=a[i] && sum!=a[k] && sum!=a[j])
						{
							cout<<a[i]<<endl;
							goto end;
						}	
					}
					
					
				}
			}
		}
		cout<<"no solution"<<endl;
		end:;
	}
	return 0;
}
