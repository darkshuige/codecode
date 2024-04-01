#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		for(int i=0;i<t;i++)
		{
			char a[1005];
			cin>>a;
			int n=strlen(a);
			int count=n;
			n--;
			int pos=0;
			while(((a[pos]=='1' && a[n]=='0') || (a[pos]=='0' && a[n]=='1')) && pos<n)
			{
				count-=2;
				pos++;
				n--;
			}
			cout<<count<<endl;
		}
	}
	return 0;
}
