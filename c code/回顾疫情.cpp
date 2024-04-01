#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
signed main()
{
	jiasu;
	priority_queue<int,vector<int>,greater<int> >q;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		q.push(op);
	}
	int cnt=0;
	int sum=0;
	while(sum<k)
	{
		int a=q.top();
		if(sum+a<=k)
		{
			sum+=a;
			cnt++;
			q.pop();
			q.push(a*2);
		}
		else
		 break;
	}
	cout<<cnt<<endl;
	return 0;
} 
