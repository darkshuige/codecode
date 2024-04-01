#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,k;
		cin>>n>>k;
		int a[10005]={0};
		a[0]=k;
		int yu=0;
		int pos=1;
		while(1)
		{
			a[pos]=a[pos-1]*n+yu;
			if(a[pos]==k)
			 break;
			yu=a[pos]/10;
			a[pos]%=10;
			pos++;
		}
		if(a[pos-1]==0)
		 cout<<0;
		else
		 for(int i=pos-1;i>=0;i--)
		  cout<<a[i];
		 cout<<endl;
	}
	return 0;
} 
