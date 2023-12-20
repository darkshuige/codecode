#include<iostream>
using namespace std;
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
		 break;
		int a[105]={0};
		int i,l,r;
		for(i=1;i<=n;i++)
		{
			cin>>l>>r;
			int j;
			for(j=l;j<=r;j++)
			 a[j]++;
		}
		for(i=1;i<=n;i++)
		{
			if(i!=1)
			 cout<<" ";
			cout<<a[i]; 
		}
		cout<<endl;
		
	}
	return 0;
}
