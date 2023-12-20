#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		string s;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			int op;
			cin>>op;
			cout<<s[op-1];
		}
		cout<<endl;
	}
	return 0;
} 
