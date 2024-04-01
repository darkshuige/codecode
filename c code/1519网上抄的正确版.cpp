#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct xx
{
	int a;
	char s[20];
}f[20000];
int cmp(xx q,xx w)
{
	return q.a<w.a;
}
int main()
{
	int t;
	scanf("%d",&t);
	for (int p=0;p<t;p++)
	{
		int n;
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		f[n].a=1;
		for (int i=0;i<n;i++)
		{
			int tt=0;
			scanf("%s",f[i].s);
			int l=strlen(f[i].s);
			for (int j=0;j<l;j++)
			{
				if (tt==0) 
				 tt=f[i].s[j]-48;
				f[i].a=f[i].a*10+f[i].s[j]-48;
			}
			
			int t=0;
			for (int j=l;j<9;j++) 
			{
				f[i].a=f[i].a*10+f[i].s[t]-48;
				t++;
				t%=l;
			}
		}
		sort(f,f+n,cmp);	
		int i=0;
		while (f[i].a==0) 
		 i++;
		if (i==n) 
		 printf("0\n");
		else
		{
			int j=0;
			while (f[i].s[j]=='0') 
			 j++;
			for (;j<strlen(f[i].s);j++) 
			 printf("%c",f[i].s[j]);
			for (j=i+1;j<n;j++) 
			 printf("%s",f[j].s);
			printf("\n");
		}
	}
	return 0;
}
