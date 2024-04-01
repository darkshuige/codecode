#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		deque<int>sb;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			sb.push_back(a);
		}
		while(!sb.empty())
		{
			cout<<sb.front()<<" "<<sb.back()<<endl;
			sb.pop_front();
			sb.pop_back();	
		}
	}
	return 0;
}
