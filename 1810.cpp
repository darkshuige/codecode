#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		priority_queue<int,vector<int>,greater<int> >q;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			q.push(a);
		}
		int sum=0;
		while(q.size()!=1)
		{
			int ss=0;
			sum+=q.top();
			ss+=q.top();
			q.pop();
			sum+=q.top();
			ss+=q.top();
			q.pop();
			q.push(ss);
		}
		cout<<sum<<endl;
	}
	return 0;
} 
