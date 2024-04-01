#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[105]={0},b[105]={0};
		int sum1=0,sum2=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
			sum1+=a[i];
			sum2+=b[i];
		}
		if(sum1%2==0 && sum2%2==0)
		{
			cout<<0<<endl;
			continue;
		}
		else if((sum1%2==0 && sum2%2!=0) || (sum1%2!=0 && sum2%2==0))
		{
			cout<<-1<<endl;
			continue;
		}
		else
		{
			int flag=0;
			for(int i=0;i<n;i++)
			{
				if((a[i]%2==0 && b[i]%2!=0) || (a[i]%2!=0 && b[i]%2==0))
				{
					flag=1;
				}
			}
			if(flag)
			 cout<<1<<endl;
			else
			 cout<<-1<<endl;
		}
	}
	return 0;
} 
