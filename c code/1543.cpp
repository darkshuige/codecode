#include<bits/stdc++.h>
using namespace std;
int a[100];
int k;
void init(long long op)
{
	k=0;
	while(op)
	{
		a[k++]=op%2;
		op=op>>1;
	}
}
bool check(int n)
{
	k=0;
	while(n)
	{
		int op=n%2;
		if(op==a[k])
		 return 1;
		k++;
		n=n>>1;
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long n;
		cin>>n;
		init(n);
		int count=0;
		for(int j=1;j<=sqrt(n);j++)
		{
			if(n%j==0)
			{
				if(check(j))
				 count++;
				if(check(n/j) && (j*j!=n))
				 count++;
			}
		}		
		cout<<count<<endl;
	}
	return 0;
}
