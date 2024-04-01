#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int i;
	for(i=0;i<t;i++)
	{
		char a[200005]={0};
		int n,d;
		cin>>n>>d;
		int j;
		for(j=0;j<n;j++)
		 cin>>a[j];
		j=0;
		if(j[0]<)
		while(j!=n)
		{
			if(*max_element(a+j,a+n)-'0'<=d)
			 break;
			j++;
		}
		int k;
		for(k=n;k>j;k--)
		{
			a[k]=a[k-1];
		}
		a[j]=d+'0';
		n++;
		cout<<a<<endl;
	}
	return 0;
} 
