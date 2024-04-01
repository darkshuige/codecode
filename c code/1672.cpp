#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int count=0;
		for(int i=0;i<n;i++)
		{
			int a[3010]={0};
			for(int j=0;j<m*3;j++)
			{
				cin>>a[j];
			}
			for(int j=0;j<m*3-2;j+=3)
			{
				int sum=a[j]+a[j+1]+a[j+2];
				if(sum>=2)
				 count++;
			}
		}
		cout<<count<<endl;	
	}
	
	return 0;
}
