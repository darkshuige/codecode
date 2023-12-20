#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
char a[maxn],b[maxn];
int nnext[maxn];
void getnext()
{
	int m=strlen(b);
	nnext[0]=0;
	int j=0;
	for(int i=1;i<m;i++)
	{
		while(j>0 && b[i]!=b[j])
		 j=nnext[j-1];
		if(b[i]==b[j])
		 j++;
		nnext[i]=j;
	}
}
int kmp(char a[],char b[])
{
	int n=strlen(a),m=strlen(b);
	int p=-1;
	int i,j=0;
	getnext();
	for(int i=0;i<n;i++)
	{
		while(j>0 && b[j]!=a[i])
		 j=nnext[j-1];
		if(b[j]==a[i])
		 j++;
		if(j==m)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	while(cin>>a>>b)
	{
		if(strcmp(a,b)==0 || strlen(a)!=strlen(b))
		{
			cout<<"no"<<endl;
			continue;
		}
		char c[maxn];
		strcpy(c,a);
		strcat(a,c);
		if(kmp(a,b))
		 cout<<"yes"<<endl;
		else
		 cout<<"no"<<endl;
	}
	return 0;
}
