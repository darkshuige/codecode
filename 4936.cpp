#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[1005];
		for(int i=0;i<n;i++)
		 cin>>a[i];
		if(n==1)
		{
			cout<<a[0]<<endl;
			cout<<-1<<endl;
			continue;
		}
		sort(a,a+n);
		cout<<a[n-1]<<endl;
		for(int i=0;i<n-1;i++)
		{
			if(i!=0)
			 cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
