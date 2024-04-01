#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[1005]={0};
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2!=0 && i%9!=0 && a[i]==0)
			{
				a[i]=1;
			}
			if(i%2==0 && i%7==0 && a[i]==0)
			{
				a[i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(i<=9 && i>=1)
				 cnt+=1;
				else if(i<=99 && i>=10)
				 cnt+=2;
				else if(i<=999 && i>=100)
				 cnt+=3;
				else if(i>=1000)
				 cnt+=4;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
