#include<iostream>
#include<stdio.h>
using namespace std;
long long qiu(int n)
{
	int i;
	long long sum=1;
	for(i=1;i<=n;i++)
	{
		sum*=i;	
	}	
	return sum;
} 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		cout<<qiu(n)<<endl;
	} 
	return 0;
}
