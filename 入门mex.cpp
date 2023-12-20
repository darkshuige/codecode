#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int n,k;
	cin>>n>>k;
	set<int>st;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		st.insert(op);	
	}
	map<int,int>flag;
	int cnt=0;
	set<int>::iterator it;
	for(it=st.begin();it!=st.end() && cnt<k;it++)
	{
		flag[*it]=1;
		cnt++;
	}
	for(int i=0;i<100005;i++)
	{
		if(!flag[i])
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
