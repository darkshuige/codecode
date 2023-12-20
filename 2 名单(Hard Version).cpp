#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f
using namespace std;
const int maxn=200005;
struct node
{
	string id,name,non;
	bool operator < (const node &a) const
    {
        return id < a.id;
    } 
};
vector<node>v;
map<node,int>mp;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		node a;
		cin>>a.id>>a.name>>a.non;
		if(!mp.count(a))
		{
			mp[a]++;
			v.push_back(a);
		}
	}
	cout<<v.size()<<endl;
	for(auto i:v)
	{
		cout<<i.id<<" "<<i.name<<" "<<i.non<<endl;
	}
	return 0;
 } 
