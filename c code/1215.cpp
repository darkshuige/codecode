#include<bits/stdc++.h>
using namespace std;
int cmp(const int a,const int b)
{
	return a>b;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int a[50];
		int i;
		for(i=0;i<n;i++)
		 cin>>a[i];
		sort(a,a+n,cmp);
		cout<<a[0]<<endl;
	}	
	return 0;
}
