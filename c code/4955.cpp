#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int a[10005]={0};
		for(int i=0;i<n;i++)
		 cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<k;i++)
		{
			if(i!=0)
			 cout<<" ";
			cout<<a[i];		
		}
		cout<<endl;
	}
	return 0;
} 
