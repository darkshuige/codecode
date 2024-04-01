#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int l,r,len,i;
	char a[]="0XZCMUACM";//0 1 2 3 4 5 6 7 8
	while(scanf("%d %d",&l,&r)!=EOF)
	{
		while(l<=r)
		{
			if(l%8==0)
			{
				cout<<a[8];
			}
			else
			{
				cout<<a[l%8];
			}
			l++;
		}
		cout<<endl;
	}
	return 0;
}
