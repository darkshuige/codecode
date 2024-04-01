#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
string A,B;
const int maxn=10;
int n;
string a[maxn],b[maxn];
int extend(queue<string> &q,map<string,int> &da,map<string,int> &db,string a[maxn],string b[maxn])
{
	int m=q.size();
	while(m--)//每一个都出列 
	{
		auto f=q.front();q.pop();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<f.size();j++)
			{
				if(f.substr(j,a[i].size())==a[i])
				{
					string s=f.substr(0,j)+b[i]+f.substr(j+a[i].size());
					if(da.count(s)) continue;
					if(db.count(s)) return da[f]+db[s]+1;
					da[s]=da[f]+1;
					q.push(s);
				}
			}
		} 
	}
	return 11;
}
int bfs()
{
	if(A==B)
	 return 0;
	queue<string>qa,qb;
	map<string,int>da,db;
	qa.push(A),qb.push(B);
	da[A]=0;db[B]=0;
	int step=10,t;
	while(step--)
	{
		if(qa.size()<=qb.size())
		{
			t=extend(qa,da,db,a,b);//从前往后 
		}
		else
		{
			t=extend(qb,db,da,b,a);//从后往前 
		}
		if(t<10)
		 return t;
	}
	return 11;
}
signed main()
{
	jiasu;
	cin>>A>>B;
	n=0;
	while(cin>>a[n]>>b[n++]);
	int t=bfs();
	if(t==11)
	 cout<<"NO ANSWER!"<<endl;
	else
	 cout<<t<<endl;
	return 0;
}
