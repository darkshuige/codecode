#include<iostream>
#include<algorithm>
int cmp(const int a,const int b)
{
	return a<b;
}
using namespace std;
int main()
{
	int n,i;
	int max=1e8;
	cin>>n;
	int a[25]={0};
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int k;
	for(i=1;i<n;i++)
	{
		int sum=a[0];
		for(k=0;k<=i;k++)
		{
			sum=sum&a[k];
		}
		if(sum<max)
		 max=sum;
	}
	cout<<max<<endl;
	return 0;
}
