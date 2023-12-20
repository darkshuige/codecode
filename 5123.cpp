#include<bits/stdc++.h>
using namespace std;
int gys(int a,int b)
{
	if(a<b)
	 swap(a,b);
	int t=a%b;
	while(t)
	{
		a=b;
		b=t;
		t=a%b;
	}
	return b;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int a,b,k;
		if(n==1)
		{
			cin>>k;
			cout<<k<<endl;
			
		}
		else if(n==2)
		{
			cin>>a>>b;
			int g=gys(a,b);
			cout<<a*b/g<<endl;
		}
		else
		{
			cin>>a>>b;
			int g=gys(a,b);
			int sum=a*b/g;
			for(int j=0;j<n-2;j++)
			{
				cin>>k;
				g=gys(sum,k);
				sum=sum*k/g;
			}	
			cout<<sum<<endl;
		}
	}
	return 0;
}
