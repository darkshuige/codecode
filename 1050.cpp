#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int n,i,j;
	char a[15];
	int b[100005]={0};
	cin>>n;
	for(i=0;i<n;i++)
	{
		int sum=0;
		scanf("%s",&a);
		for(j=0;j<strlen(a);j++)
		{
			sum+=(int)(a[j]);
		}
		j=0;
		while(sum)
		{
			b[j]=sum%2;
			sum=sum/2;
			j++;
		}
		for(j--;j>=0;j--)
		{
			cout<<b[j];
		}
		cout<<endl;
		
	}
	return 0;
}
