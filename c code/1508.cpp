#include<bits/stdc++.h>
using namespace std;
int a[100005]={0};
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	for(int i=0;i<q;i++)
	{
		int k;
		cin>>k;
		if(!binary_search(a,a+n,k))
		{
			cout<<k<<" not found"<<endl;
		}
		else
		{
			cout<<k<<" found at "<<lower_bound(a,a+n,k)-a<<endl;
		}
	}
	return 0;
} 
