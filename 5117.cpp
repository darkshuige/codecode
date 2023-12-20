#include<bits/stdc++.h>
using namespace std;
int act(char a)
{
	if(a=='(')
	 return 1;
	else if(a==')')
	 return 2;
	else if(a=='[')
	 return 3;
	else if(a==']')
	 return 4;
	else if(a=='{')
	 return 5;
	else if(a=='}')
	 return 6;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a[10]={0};
		string s;
		cin>>s;
		int flag=1;
		int len=s.size();
		if(len%2!=0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		for(int j=0;j<len;j++)
		{
			int op=act(s[j]);
			if(op==1 || op==3 || op==5)
			 a[op]++;
			else
			{
				if(a[op-1]>0)
				 a[op-1]--;
				else
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
}
//1 2 3 4 5 6
//( ) [ ] { }
