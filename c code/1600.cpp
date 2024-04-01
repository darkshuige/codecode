#include<bits/stdc++.h>
using namespace std;
char a[1000005]={0};
char b[1000005]={0};
int main()
{
	while(cin>>a)
	{
		int n;
		cin>>n;
		int len=strlen(a);
		b[0]='@';
		b[1]='#';
		int k=2;
		for(int i=0;i<len;i++)
		{
			b[k]=a[i];
			b[k+1]='#';		
			k+=2;
		}
		b[k]='$';
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
	}
	return 0;
} 
