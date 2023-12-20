#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cmp(const int a,const int b)
{
	return a>b;
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		 cin>>a[i];
		sort(a,a+n,cmp);
		for(int i=0;i<m;i++)
		{
			if(i!=0)
			 cout<<" ";
			cout<<a[i];
		}
		cout<<endl;	
	}
	
	return 0;
}
