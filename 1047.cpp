#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		int count=0;
		i=1;
		while(i<n)
		{
			i=i*2;
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
