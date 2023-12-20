#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int a[10];
	cin>>s;
	set<int>sb;
	for(int i=0;i<s.size();i++)
	{
		sb.insert((s[i]-'0'));
	}
	printf("int[] arr = new int[]{");
	int count=0;
	set<int>::iterator it;
	for(it=sb.end();it!=sb.begin();it--)
	{
		if(it==sb.end())
		 continue;
		if(count!=0)
		 cout<<",";
		cout<<*it;
		a[count]=*it;
		count++;
	}
	if(count!=0)
	cout<<",";
	cout<<*it;
	a[count]=*it;
	count++;
	printf("};\n");
	printf("int[] index = new int[]{");
	int op=count;
	count=0;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<op;j++)
		{
			if(a[j]==s[i]-'0')
			{
				if(count!=0)
				 cout<<",";
				cout<<j;
				count++;
			}
		}
	}
	printf("};\n");
	return 0;
}
