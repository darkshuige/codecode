#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,i,j;
	cin>>t;
	getchar();
	for(i=0;i<t;i++)
	{
		int count=0;
		char a[100005]={0};
		gets(a);
		for(j=0;j<strlen(a);j++)
		{
			if(j!=0)
			{
				if(a[j-1]==' ' && a[j]!=' ')
				{
					count++;
				}
			}
		}
		if(a[0]!=' ')
		{
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
