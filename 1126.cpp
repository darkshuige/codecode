#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int max(int a[])
{
	int i;
	int max=0;
	for(i=0;i<=25;i++)
	 if(a[i]>a[max])
	  max=i;
	return a[max];
}
int main()
{
	char b;
	int a[27]={0},m;
	while(cin>>b)
	{
		if((b>='a' && b<='z') || (b>='A' && b<='Z'))
		{
			a[tolower(b)-'a']++;
		}
	}
	m=max(a);
	int i;
	while(m!=0)
	{
		for(i=0;i<=25;i++)
		{
			if(i!=0)
			 cout<<" ";
			if(a[i]==m)
			{
				cout<<"*";
				a[i]--;
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;	
		m=max(a);
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
	return 0;
}
