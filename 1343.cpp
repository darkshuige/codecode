#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[32780]={0};
	for(int i=2;i<32780;i++)
	{
	   	for(int j=i*2;j<32780;j+=i)
	    {
	       	a[j]++;
	    }
	}
	int n;
	while(cin>>n)
	{
		int count=0;
		if(n==0)
		 break;
		for(int i=2;i<=n/2;i++)
		{
			if(a[i]==0 && a[n-i]==0)
			 count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
