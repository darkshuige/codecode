#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[10200]={0};
	while(cin>>a)
	{
		if(a[0]=='0') break;
		int s=17;
		int sum=0;
		for(int i=0;i<strlen(a);i++)
		{
			sum=sum*10+(a[i]-48);
			sum%=s;
		}
		if(sum==0)
	     cout<<1<<endl;
		else
		 cout<<0<<endl;
	}
	return 0;
}
