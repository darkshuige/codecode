#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
void f(int n,set<int>&st,set<int>&st2)
{
	for(int i=1;i*i<=n;i++) 
	{
		if(n%i==0) 
		{
			st.insert(i);
			st2.insert(i);
			if(i!=n/i)
			{
				st.insert(n/i);
				st2.insert(n/i);
			}
		}
	}
}
signed main()
{
	jiasu;
	int n;
	int a,b;
	cin>>a>>b;
	set<int>st1,st2,st3;
	f(a,st1,st3),f(b,st2,st3);
	for(auto i:st1)
	{
		for(auto j:st2)
		{
			st3.insert(i*j);
		}
	}
	cout<<st3.size()<<endl;
	int cnt=0;
	for(auto it=st3.begin();it!=st3.end();it++)
	{
		if(cnt!=0)
		 cout<<" ";
		cnt++;
		cout<<*it;
	}
	cout<<endl;
	return 0;
}
