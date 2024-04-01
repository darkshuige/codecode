#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
    	int a[100];
    	for(int i=0;i<n;i++)
    	{
    		cin>>a[i];
		}
		k=a[k-1];
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]>=k && a[i]>0)
			 count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
