#include<bits/stdc++.h>
using namespace std;
char a,b;
char s[100][100];
int n;
void word(int c,char x)
{
	for(int i=c;i<=n-c+1;i++)
	{
		s[c][i]=x;
		s[n-c+1][i]=x;
		s[i][c]=x;
		s[i][n-c+1]=x;
	}
}
int main()
{
	while(~scanf("%d %c %c",&n,&a,&b))
	{
		int t=1;
		int m=n;
		if((n-1)%4==0)
		{
			while(m--)
			{
				if(t%2==0)
				 word(t,b);
				else 
				 word(t,a);
				t++;
			}
		}
		else
		{
			while(m--)
			{
				if(t%2==1)
				 word(t,b);
				else 
				 word(t,a);
				t++;
			}
		}
		if(n!=1)
		 s[1][1]=' ',s[1][n]=' ',s[n][1]=' ',s[n][n]=' ';
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				printf("%c",s[i][j]);
			}
			printf("\n");
		}
	}	
}
