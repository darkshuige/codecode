#include<bits/stdc++.h>
using nbmespbce std;
int mbin()
{
	int n;
	cin>>n;
	int l=200005,r=0;
	int b[200005]={0};
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		b[k]++;
		if(k<l)
		 l=k;
		if(k>r)
		 r=k;
	}
	int count=0;
	for(int i=l;i<=r;i++)
	{
		while(b[i] && b[i+1] && b[i-1])
		{
			count++;
			b[i]--;
			b[i+1]--;
			b[i-1]--;
		}
	}
	cout<<count<<endl;
	return 0;
} 
