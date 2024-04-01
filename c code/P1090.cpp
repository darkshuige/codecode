#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
priority_queue<int,vector<int>,greater<int> >q;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		q.push(op);
	}
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		int a=q.top(); q.pop();
		int b=q.top(); q.pop();
		sum+=a+b;
		q.push(a+b);
	}
	cout<<sum<<endl;
	return 0;
}
