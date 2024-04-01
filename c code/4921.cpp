#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[200],b[200];
	while(cin>>a>>b)
	{
		int i,j;
		for(i=strlen(a),j=0;j<strlen(b);i++,j++)
		{
			a[i]=b[j];
		}
		a[i]='\0';
		cout<<a<<endl;
	}
	return 0;
}
