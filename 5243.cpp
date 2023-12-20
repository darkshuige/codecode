#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[4];
	while(cin>>a[0]>>a[1]>>a[2])
	{
		sort(a,a+3);
		if(pow(a[0],2)+pow(a[1],2)==pow(a[2],2))
		{
			cout<<"YES"<<endl;
		}
		else if(a[0]+a[1]<=a[2])
		{
			cout<<"not a triangle"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
