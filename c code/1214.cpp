#include<bits/stdc++.h>
using namespace std;
int a[25];
void fb()
{
	a[0]=1;
	a[1]=1;
	int i;
	for(i=2;i<25;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
}
int main()
{
	fb();
	int n;
	while(cin>>n)
	{
		cout<<a[n]<<endl;
	}
	return 0;
}
