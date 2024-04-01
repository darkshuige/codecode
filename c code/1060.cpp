#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,c,s1=0,s2=0;
		int a[205]={0};
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cin>>c;
		sort(a,a+n+1);
		for(i=0;i<=n;i++)
		{
			s1=s1+abs(a[i]-a[(1+n)/2]);
			s2=s2+abs(a[i]-a[(1+n)/2+1]);
		}
		if(s1<s2)
		 cout<<s1*c<<endl;
		else
	     cout<<s2*c<<endl;
	}
	return 0;
} 
