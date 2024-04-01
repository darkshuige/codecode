#include<iostream>
using namespace std;
int gys(int a,int b)
{
	int t;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	t=a%b;
	while(t!=0)
	{
		a=b;
		b=t;
		t=a%b;
	}
	return b;
}
int main()
{
	int n,t,i,j,a[1]={0},flag=0;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>a[flag];
			if(j!=0)
			 a[flag]=gys(a[0],a[1]);
			flag=!flag;
		}
		cout<<a[!flag]<<endl;
	}
	return 0;
}
