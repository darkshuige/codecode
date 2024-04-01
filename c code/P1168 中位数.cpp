#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
priority_queue<int>a;//大根堆
priority_queue<int,vector<int>,greater<int> >b;//小根堆 
signed main()
{
	jiasu;
	int n; 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(b.size()==0 || x>b.top())
		 b.push(x);
		else
		 a.push(x);
		int k=(i+1)/2;
		while(b.size()<k)
		{
			b.push(a.top());
			a.pop();
		}
		while(b.size()>k)
		{
			a.push(b.top());
			b.pop();
		}
		if(i%2==1)
		 cout<<b.top()<<endl;
	}
	return 0;
}
