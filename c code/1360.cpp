#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		 cin>>a[i];
		sort(a,a+n);
		int sum=0;
		for(int i=1;i<n-1;i++)
		 sum+=a[i];
		printf("%.2f\n",(double)(sum)/(double)(n-2));
	}	
	return 0;
} 
