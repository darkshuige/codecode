#include<iostream>
using namespace std;
int main()
{
	char b[100000]={0}; 
	char a[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int t,i,n,j;
	cin>>t; 
	for(i=0;i<t;i++)
	{
		cin>>n;
		j=0;
		while(n)
		{
			b[j]=n%16;
			n=n/16;
			j++;
		}
		for(j=j-1;j>=0;j--)
		 cout<<a[b[j]];
		cout<<endl;
	}
	return 0;
}
