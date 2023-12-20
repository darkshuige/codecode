#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<char>sb;
	char a;
	while(cin>>a)
	{
		sb.push(a);
	}
	while(!sb.empty())
	{
		a=sb.top();
		cout<<a;
		sb.pop();
	}
	cout<<endl;
	return 0;
}
