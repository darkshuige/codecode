#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,sum,a,i;
	while(cin>>n && n!=0)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a;
			sum+=pow(a,2);
		}
		cout<<sum<<endl;
	}
	return 0;
}
