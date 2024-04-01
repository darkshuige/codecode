#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string.h>
using namespace std;
int main()
{
	char k[110]={0};
	int n;
	while(scanf("%s %d",&k,&n)!=EOF)
	{
		if(n<=strlen(k)-2) 
		 cout<<k[n+1]<<endl;
		else
		 cout<<"0"<<endl;
		memset(k,0,sizeof(k));
	}
	return 0;
}
