#include<bits/stdc++.h>
using namespace std;
int check(int a)
{
	if(a%7==0)
	 return 1;
	int flag=0;
	while(a)
	{
		if(a%10==7)
		{
			return 1;
		}
		a/=10;
	}
	return 0;
}
int main()
{
	int n,m,k;
	while(cin>>n>>m>>k)
	{
		if(n==0 && k==0 && m==0) break;
		int count=0;
		int sum=1;
		int pos=1;
		int flag=-1;
		while(count!=k)
		{
			if(pos==1 || pos==n)
			{
				flag=-flag;
			}
			if(pos==m && check(sum))
			{
				count++;
			}
			if(flag==1)
			{
				pos++;
			}
			else if(flag==-1)
			{
				pos--;
			}
			sum++;
		}
		cout<<sum-1<<endl;
	}
	return 0;	
}
