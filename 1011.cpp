#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int w;
	while(scanf("%d",&w)!=EOF)
	{
		if(w%2==0 && w>2)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
