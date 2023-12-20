#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[12]={0};
	while(cin>>a[1])
	{
		for(int i=2;i<=10;i++)
		 cin>>a[i];
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			a[k]+=10;
		}
		for(int i=1;i<=10;i++)
		{
			if(i!=1)
			 cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
