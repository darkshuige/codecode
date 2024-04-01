#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[100005]={0};
		int i,op,max=-1;
		for(i=0;i<n;i++)
		{
			cin>>op;
			a[op]++;
			if(a[op]>a[max])
			{
				max=op;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
