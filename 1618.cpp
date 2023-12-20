#include<bits/stdc++.h>
using namespace std;
int a[100005];
void init()
{
	a[1]=1;
	a[2]=2;
	for(int i=3;i<100005;i++)
	 a[i]=(a[i-1]+a[i-2])%19999997;
}
int main()
{
	init();
	int n;
	while(cin>>n)
	 cout<<a[n]<<endl;
	return 0;
}
