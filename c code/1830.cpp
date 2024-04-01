#include<bits/stdc++.h>
using namespace std;
char op[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
	long long a;
	while(cin>>a)
	{
		if(a==0)
		{
			cout<<0<<endl;
			continue;
		}
		int b[100]={0};
		int k=0;
		while(a)
		{
			b[k++]=a%16;
			a/=16;
		}
		int flag=0;
		for(int i=k-1;i>=0;i--)
		{
			if(flag==0)
			{
				if(b[i]==0)
				 continue;
				else
				{
					flag=1;
					cout<<op[b[i]];
				}
			}
			else
			{
				cout<<op[b[i]];
			}
		}
		cout<<endl;
	}
	return 0;
}
