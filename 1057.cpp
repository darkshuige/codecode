#include<iostream>
using namespace std;
int main()
{
	int i,t;int a[1005]={0};
	cin>>t;
	int j=1;
	a[1]=1;
	for(i=2;i<=1000;i++)
	{
		a[i]=a[i-1]+j;
		if(i==9 || i== 99)
		 j++;
	}
	for(i=0;i<t;i++)
	{
		int n,flag=0;
		cin>>n;
		for(j=1;j<=1000;j++)
		{
			if(a[j]==n)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		 cout<<j<<endl;
		else
		 cout<<"-1"<<endl;
	}
	return 0;
}
