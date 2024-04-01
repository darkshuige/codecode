#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
int gx[]={-1,0,0,0,1,2,2,2,1};
int gy[]={-1,0,1,2,2,2,1,0,0};
int ex[5]={0,-1,+0,+1,+0};
int ey[5]={0,+0,+1,+0,-1};
int f(string s)
{
	int ans=0;
	for(int i=0;i<9;i++)
	{
		int t=s[i]-'0';
		if(t) ans+=abs(t/3-gx[t])+abs(t%3-gy[t]);
	}
	return ans;
}
int astar(string s)
{
	string end="123804765";
	map<string,int>d;
	priority_queue<pair<int,string> >q;
	q.push({-f(s),s});d[s]=0;
	while(!q.empty())
	{
		auto a=q.top();q.pop();
		string s=a.second;
		if(s==end) return d[s];
		int k=s.find("0");
		int x=k/3,y=k%3;
		for(int i=1;i<=4;i++)
		{
			int a=x+ex[i],b=y+ey[i];
			if(a<0 || a>=3 || b<0 || b>=3) continue;
			string ss=s;
			swap(ss[k],ss[a*3+b]);
			if(!d.count(ss))
			{
				d[ss]=d[s]+1;
				q.push({-(d[ss]+f(ss)),ss});
			}
		}
	}
}
signed main()
{
	jiasu;
	string s;
	cin>>s;
	cout<<astar(s)<<endl;
	return 0;
}
