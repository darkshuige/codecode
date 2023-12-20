#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[110]={0};
		int b[110]={0};
		int i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		cout<<(a[n-1]-a[0])*(b[n-1]-b[0])<<endl;
	}
	return 0;
}
