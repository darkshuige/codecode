#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
int ex[5]={0,-1,+0,+1,+0};
int ey[5]={0,+0,+1,+0,-1};
map<string,int>d;
int bfs(string s)
{
	string end="123804765";
	queue<string>q;
	q.push(s);
	while(!q.empty())
	{
		string op=q.front();
		q.pop();
		if(op==end) return d[op];
		int k=op.find("0");
		int x=k/3,y=k%3;
		for(int i=1;i<=4;i++)
		{
			int a=x+ex[i],b=y+ey[i];
			if(a<0 || a>=3 || b<0 || b>=3) continue;
			int dis=d[op];
			swap(op[k],op[a*3+b]);
			if(!d.count(op))
			{
				d[op]=dis+1;
				q.push(op);
			}
			swap(op[k],op[a*3+b]);
		}
	}
}
signed main()
{
	jiasu;
	string s;
	cin>>s;
	cout<<bfs(s)<<endl;
	return 0;
}
