#include<bits/stdc++.h>
using namespace std;
char a[100005],b[100005];
int c[100005];
int main()
{
	while(cin>>a>>b)
	{
		reverse(a,a+strlen(a)),reverse(b,b+strlen(b));
		int len=max(strlen(a),strlen(b));
		memset(c,0,sizeof c);
		for(int i=0;i<len;i++)
		 c[i]=((a[i]-48)+(b[i]-48))%10;
		len--;
		while(c[len]==0)
		 len--;
		for(int i=len;i>=0;i--)
		 cout<<c[i];
		cout<<endl;
	}
	return 0;	
}
