#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#include<stack>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=110;
int vis[maxn][maxn];
int d[maxn][maxn];
pair<int,int>f[maxn][maxn];
int op[maxn][maxn];
int c,flag;
int ma,mb;
int ans,x,y;
vector<int>v;
void bfs(int a,int b)
{
	queue<pair<int,int> >q;
	memset(vis,0,sizeof vis);
	vis[0][0]=1;
	memset(d,0,sizeof d);
	d[0][0]=0;
	pair<int,int>p;
	p.first=a;p.second=b;
	q.push(p);
	while(!q.empty() && flag==0)
	{
		pair<int,int>p;
		p=q.front();q.pop();
		int a=p.first,b=p.second;
		if(a==c || b==c)
		{
			flag=1;
			x=a,y=b;
			ans=d[a][b];
			break;
		}
		if(a!=ma && vis[ma][b]==0)
		{
			vis[ma][b]=1;
			d[ma][b]=d[a][b]+1;
			f[ma][b]=make_pair(a,b);
			op[ma][b]=1;
			q.push(make_pair(ma,b));
		}
		if(b!=mb && vis[a][mb]==0)
		{
			vis[a][mb]=1;
			d[a][mb]=d[a][b]+1;
			f[a][mb]=make_pair(a,b);
			op[a][mb]=3;
			q.push(make_pair(a,mb));
		}
		if(a && vis[0][b]==0)
		{
			vis[0][b]=1;
			d[0][b]=d[a][b]+1;
			f[0][b]=make_pair(a,b);
			op[0][b]=2;
			q.push(make_pair(0,b));
		}
		if(b && vis[a][0]==0)
		{
			vis[a][0]=1;
			d[a][0]=d[a][b]+1;
			f[a][0]=make_pair(a,b);
			op[a][0]=4;
			q.push(make_pair(a,0));
		}
		if(a!=ma && b)//b¸øa 
		{
			if(a+b<=ma && vis[a+b][0]==0)
			{
				vis[a+b][0]=1;
				d[a+b][0]=d[a][b]+1;
				f[a+b][0]=make_pair(a,b);
				op[a+b][0]=6;
				q.push(make_pair(a+b,0));
			}
			else if(a+b>ma && vis[ma][a+b-ma]==0)
			{
				vis[ma][a+b-ma]=1;
				d[ma][a+b-ma]=d[a][b]+1;
				f[ma][a+b-ma]=make_pair(a,b);
				op[ma][a+b-ma]=6;
				q.push(make_pair(ma,a+b-ma));
			}
		}
		if(b!=mb && a)
		{
			if(a+b<=mb && vis[0][a+b]==0)
			{
				vis[0][a+b]=1;
				d[0][a+b]=d[a][b]+1;
				f[0][a+b]=make_pair(a,b);
				op[0][a+b]=5;
				q.push(make_pair(0,a+b));
			}
			else if(a+b>mb && vis[a+b-mb][mb]==0)
			{
				vis[a+b-mb][mb]=1;
				d[a+b-mb][mb]=d[a][b]+1;
				f[a+b-mb][mb]=make_pair(a,b);
				op[a+b-mb][mb];
				q.push(make_pair(a+b-mb,mb));
			}
		}	
	}
	
}
signed main()
{
	flag=0;
	v.clear();
	cin>>ma>>mb>>c;
	bfs(0,0);
	if(flag==0)
	 cout<<"impossible"<<endl;
	else
	{
		cout<<ans<<endl;
		stack<int>st;
		while(!(x==0 && y==0))
		{
			st.push(op[x][y]);
			int xx=x;
			x=f[x][y].first;
			y=f[xx][y].second;
		}
		while(!st.empty())
		{
			int op=st.top();st.pop();
			if(op==1)
				cout<<"FILL(1)"<<endl;
			else if(op==3)
				cout<<"FILL(2)"<<endl;
			else if(op==2)
				cout<<"DROP(1)"<<endl;
			else if(op==4)
				cout<<"DROP(2)"<<endl;
			else if(op==5)
				cout<<"POUR(1,2)"<<endl;
			else if(op==6)
				cout<<"POUR(2,1)"<<endl;
		}
	}
	return 0;
}
