#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
int sr[maxn];
priority_queue<int>a;//大根堆
priority_queue<int,vector<int>,greater<int> >b;//小根堆 
signed main()
{
	jiasu;
	int m,n; 
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	 cin>>sr[i];
	int p=1;
	for(int i=1;i<=n;i++)
	{
		int p2;
		cin>>p2;
		for(p;p<=p2;p++)
		{
			int x=sr[p];
			if(a.size()==0 || x<a.top())
			 a.push(x);
			else
			 b.push(x);
		}	 
		int k=i;
		while(a.size()<k)
		{
			a.push(b.top());
			b.pop();
		}
		while(a.size()>k)
		{
			b.push(a.top());
			a.pop();
		}
		cout<<a.top()<<endl;
	}
	return 0;
}
