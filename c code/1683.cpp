#include<bits/stdc++.h>
using namespace std;
int a[1000005]={0};
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		 a[i]=i;
		sort(a+1,a+1+n);
		do
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=1)
				 cout<<" ";
				cout<<a[j];
			}
			cout<<endl;
		}while(next_permutation(a+1,a+1+n));
	}
	return 0;
}
