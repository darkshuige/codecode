#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int count=0;
		int da,xiao;
		if(n>m)
		{
			da=n;
			xiao=m;
		}
		else
		{
			da=m;
			xiao=n;
		}
		count+=(n-1);
		count+=(m-1)*n;
		cout<<count<<endl;
	}
	return 0;
}
