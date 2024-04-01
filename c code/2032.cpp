#include<bits/stdc++.h>
using namespace std;
int c[10005];
int main()
{
	int t,i,flag=0;
	string a,b,op;
	while(cin>>a>>b)
	{
		memset(c,0,sizeof c);
		if(a.size()<b.size())//a³¤b¶Ì 
		{
			op=a;
			a=b;
			b=op;
		}
		int k=0;
		int j=0;
		int l=0;
		for(j=b.size()-1,l=a.size()-1;j>=0;j--,l--)
		{
			c[k]=(a[l]-'0')+(b[j]-'0');
			k++;
		}
		for(l;l>=0;l--)
		{
			c[k]=a[l]-'0';
			k++;
		}
		for(j=0;j<k-1;j++)
		{
			c[j+1]+=c[j]/10;
			c[j]%=10;
		}
		if(c[k]>=10)
		{
			c[k+1]+=c[k]/10;
			c[k]%=10;
			k++;
		}
		for(j=k-1;j>=0;j--)
		{
			cout<<c[j];
		}
		cout<<endl;
	}
	
	return 0;
}
