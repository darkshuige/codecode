#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int l,i,count=0;
	char s[105];
	int a[26]={0};
	while(scanf("%s",&s)!=EOF)
	{
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(a[s[i]-'a']==0)
			 count++;
			a[s[i]-'a']++;
		}
		if(count%2==0)
		{
			cout<<"CHAT WITH HER!"<<endl;
		}
		else
		{
			cout<<"IGNORE HIM!"<<endl;
		}
		count=0;
		for(i=0;i<26;i++)
		 a[i]=0;
	}
	return 0;
} 
