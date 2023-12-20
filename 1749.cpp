#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	while(cin>>n)
	{
		int a[30]={0};
		int flag=0;
		if(n<0)
		{
			flag=1;
			n=-n;
		}
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}
		int k=0;
		while(n)
		{
			a[k++]=n%10;
			n/=10;
		}
		if(flag)
		 cout<<"-";
		flag=0;
		if(a[0]==0)
		{
			flag=1;
		}
		for(int i=0;i<k;i++)
		{
			if(flag==1)
			{
				if(a[i]==0)
				 continue;
				else
				{
					cout<<a[i];
					flag=0;
				}
			}
			else if(flag==0)
			 cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
