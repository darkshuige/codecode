#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
struct node
{
	int id;
	int num;
	friend bool operator < (node a,node b)
	{
        return a.num>b.num;
    }
}a;
priority_queue<node>q;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a.id>>a.num;
		q.push(a);
	}
	while(1)
	{
		node op=q.top();q.pop();
		if(op.num==1) break;
		if(op.num%2==0)
		{
			node a;a.id=op.id*2,a.num=op.num/2;
			q.push(a);
		}
		else
		{
			node a;a.id=op.id*2,a.num=op.num/2;
			q.push(a);
			a.id=op.id,a.num=1;
			q.push(a);
		}
	}
	cout<<q.size()<<endl;
	return 0;
}
