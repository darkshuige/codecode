#include<bits/stdc++.h>
using namespace std;
int a[100005]={0};
int m=10000;
void init()
{
	a[0]=0;
	int sp=1;
	for(int i=1;i<100005;i++)
	{
		a[i]=a[i-1]+sp;
		a[i]%=m;
		sp+=2;
	}
}
int main()
{
	init();
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			cout<<a[k]<<endl;
		}
	}
	return 0;
}
