#include<iostream>
using namespace std;
int main()
{
	int a[50]={0};
	a[0]=1;
	a[1]=1;
	int i;
	for(i=2;i<50;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	int n;
	while(cin>>n)
	{
		int flag=0;
		for(i=1;i<50;i++)
		{
			if(a[i]==n)
			{
				cout<<"Second win"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"First win"<<endl;
		}
	}
	return 0;
}
