#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
signed main()
{
	jiasu;
	int n,m,k;
	cin>>n>>m>>k;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		q.push(op);
	}
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>x;
			q.push(x);
		}
		else
		{
			if(q.size()<k)
			{
				cout<<-1<<endl;
				continue;
			}
			auto cp=q;
			for(int i=1;i<k;i++)
			 q.pop();
			cout<<q.top()<<endl;
			q=cp;
		}
	}
	return 0;
} 
