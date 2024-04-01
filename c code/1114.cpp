#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[]="Jbuu~'Dountsjft'sh'~hr'YQY'&";	
	int i;
	char b[100]={0};
	for(i=0;i<strlen(a);i++)
	{
		b[i]=a[i]^7;
	}
	cout<<b<<endl;
} 
