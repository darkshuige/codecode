#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
priority_queue<int,vector<int>,less<int> >q;
signed main()
{
	jiasu;
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		q.push(op);
	}
	int time=0,op=q.top();
	while(op>time*a)
	{
		q.pop();
		time++;
		op-=b;
		q.push(op);
		op=q.top();
	}
	cout<<time<<endl;
	return 0;
}
