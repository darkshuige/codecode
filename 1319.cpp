#include<bits/stdc++.h>
using namespace std;
int cmp(const int a,const int b)
{
	return abs(a)>abs(b);
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		 break;
		int a[105];
		int i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
		{
			if(i!=0)
			 cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
 } 
