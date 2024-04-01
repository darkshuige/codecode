#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		int sum=0;
		for(int i=1;i<=t;i++)
		{
			string s;
			cin>>s;
			sum+=(s[s.size()-1]-48);
		}
		cout<<sum<<endl;
	}
	return 0;
}
