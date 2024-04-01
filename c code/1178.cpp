#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num[4]={2,3,5,7};
	set<long long>s;
	priority_queue<long long,vector<long long>,greater<long long> >q;
	vector<long long>v;
	s.insert(1);
	q.push(1);
	for(int j=1;j<=5842;j++)
	{
		long long a=q.top();
		q.pop();
		v.push_back(a);
		for(int i=0;i<4;i++)
		{
			long long b=a*num[i];
			if(!s.count(b))
			{
				s.insert(b);
				q.push(b);
			}
		}
	}
	int n;
	while(cin>>n)
	{
		cout<<v[n-1]<<endl;
	}
	return 0;
}
