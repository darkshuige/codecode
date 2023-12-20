#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
bool cmp(const int a,const int b)
{
	return abs(a)<abs(b);
}
int main()
{
	int t,i,n,j,sum=0,count=0;
	int a[200005];
	cin>>t;
	for(i=0;i<t;i++)
	{
		sum=0;
		count=0;
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>a[j];
			if(a[j]<0)
			{
				count++;
			}
		}
		if(count%2==0)
		{
			for(j=0;j<n;j++)
			 sum+=abs(a[j]);
		}
		else
		{
			sort(a,a+n,cmp);
			sum+=a[0];
			for(j=1;j<n;j++)
			 sum+=abs(a[j]);
		}
		cout<<sum<<endl;
	}
	return 0;
}
