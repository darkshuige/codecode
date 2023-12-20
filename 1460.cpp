#include<bits/stdc++.h>
using namespace std;
int a[1000005]={0};
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		memset(a,0,sizeof a);
		for(int j=0;j<n;j++)
		 cin>>a[j];
		sort(a,a+n);
		if(a[n-1]*a[n-1]-4*a[1]*a[0]>=0)
		{
			printf("%d %d %d\n",a[0],a[n-1],a[1]);
		}
		else
		 cout<<"impossible"<<endl;
	}
	return 0;
}
