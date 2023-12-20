#include<iostream>
using namespace std;
bool a[1000000]={0};
int sum[10000];
void init()
{
	int i,j;
	for(i=1;i<=5000;i++)
	{
		for(j=2;j*i<=5000;j++)
		{
			sum[j*i]+=i;
		}
		if(sum[i]<=1000)
		{
			a[sum[i]]=1;
		}
	}
}
int main()
{
	init();
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		if(a[n]) 
		 cout<<"no"<<endl;
		else
		 cout<<"yes"<<endl;
	}
	return 0;
}
