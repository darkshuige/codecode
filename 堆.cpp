#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cou.tie(0)
#define int long long
#define endl "\n"
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
signed main() 
{
	int n;
	cin>>n;
	int now=0;
	while(n--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>x;
			q.push(x-now);
		}
		else if(op==2)
		{
			cout<<q.top()+now<<endl;
			q.pop();
		}
		else
		{	
			int c;
			cin>>c;
			now+=c;
		}
	}
    return 0;
}