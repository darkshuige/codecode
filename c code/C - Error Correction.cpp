#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000050;
const int mod=998244353;
int check1(string s,string t)
{
	int sum=0;
	for(int i=0,j=0;i<t.size();i++,j++)
	{
		if(t[i]!=s[j])
		{
			sum++;
			j--;
		}
	}
	if(sum<=1)
	 return 1;
	else
	 return 0;
}
int check3(string s,string t)
{
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=t[i])
		 sum++;
	}
	if(sum==1)
	 return 1;
	else
	 return 0;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	string t;
	cin>>t;
	set<int>st;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(s==t)
		 st.insert(i);
		else if(s.size()==t.size()-1 && check1(s,t))
		 st.insert(i);
		else if(s.size()==t.size()+1 && check1(t,s))
		 st.insert(i);
		else if(s.size()==t.size() && check3(s,t))
		 st.insert(i);
	}
	cout<<st.size()<<endl;
	int cnt=0;
	for(auto k:st)
	{
		if(cnt!=0) cout<<" ";
		cnt++;
		cout<<k;
	}
	cout<<endl;
	return 0;
}
//jttcoder
// atcoder
