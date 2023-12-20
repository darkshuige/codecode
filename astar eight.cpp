#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
int rres;
int gx[20]; //目标坐标
int gy[20];


int f(string s)
{ //估价函数: 曼哈顿距离之和
  int res=0;
  for(int i=0; i<9; i++)
  {
    int t=s[i]-'0';
    if(t) res+=abs(i/3-gx[t])+abs(i%3-gy[t]);
  }
  return res;
}


void astar(string s,string ed)
{
	string st=s;
	int ex[]={+1,+0,-1,+0};
	int ey[]={+0,-1,+0,+1};
	char op[]={'d','l','u','r'};
	map<string,pair<string,char> >mp;
	priority_queue<pair<int,string>,vector<pair<int,string> >,greater<pair<int,string> > >q;
	map<string,int>d;
 	d[s]=0;
	q.push(make_pair(f(s),s));
	while(!q.empty())
	{
		string s=q.top().second;q.pop();
		if(s==ed) break;
		int p=s.find("X");
		int x=p/3,y=p%3;
		string ss=s;
		for(int i=0;i<4;i++)
		{
			int xx=x+ex[i],yy=y+ey[i];
			if(xx<0 || xx>=3 || yy<0 || yy>=3) continue;
			swap(s[p],s[yy+xx*3]);
			if(mp.count(s)==0)
			{
				d[s]=d[ss]+1;
				mp[s]=make_pair(ss,op[i]);
				q.push(make_pair((f(s)+d[s]),s));
			}
			s=ss;
		}
	}
	string ans="";
	int rres=d[ed];
	while(ed!=st)
	{
		ans+=mp[ed].second;
		ed=mp[ed].first;
	}
	reverse(ans.begin(),ans.end());
	cout<<rres<<endl;
	cout<<ans<<endl;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		string a,b;
		cin>>a>>b;
		for(int j=0;j<b.size();j++)
		{
			int t=b[j]-'0';
			if(t)
			{
				int x=j/3,y=j%3;
				gx[t]=x,gy[t]=y;
			}
		}
		cout<<"Case "<<i<<": ";
		astar(a,b);
	}
	return 0;
}
