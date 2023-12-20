#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		fill(a,a+1000004,1);
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			int k;
			cin>>k;
			a[k]=0;
		}
		int count=0;
		int j=1;
		while(count!=2)
		{
			if(a[j]==1)
			{
				if(count!=0)
				 cout<<" ";
				cout<<j;
				count++;
			}
			j++;
		}
		cout<<endl;
	}
	return 0;
}
