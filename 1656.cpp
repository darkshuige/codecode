#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int a[2005]={0};
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		sort(a+1,a+n+1);
		cout<<a[k]<<endl;
	}
	return 0;
}
