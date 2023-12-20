#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int pos=2;
		int count=1;
		while(pos!=1)
		{
			if(pos/n>0 && pos!=n)
			{
				if(pos%n==0)
				 pos=n;
				else
				 pos=pos%n;
				pos=pos*2-1;
			}
			else
			{
				pos=pos*2;
			}
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
