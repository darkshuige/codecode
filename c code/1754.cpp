#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	char op,d;
	int count=0;
	while(scanf("%d%c%d%c",&a,&op,&b,&d)!=EOF)
	{
		string s;
		cin>>s;
		int sum=0;
		if(s[0]=='?')
		{
			continue;
		}
		else
		{
			for(int k=0;k<s.size();k++)
			{
				sum=sum*10+(s[k]-48);
			}
			int as;
			if(op=='+')
			 as=a+b;
			else if(op=='-')
			 as=a-b;
			if(as==sum)
			 count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
