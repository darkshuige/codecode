#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int m,s,c;
	cin>>m>>s>>c;
	set<int>st;
	for(int i=0;i<c;i++)
	{
		int op;
		cin>>op;
		st.insert(op);
	}	
	if(st.size()<=m)
	{
		cout<<st.size()<<endl;
	}
	else
	{
		int a[300],d[300];
		int pos=0;
		for(auto k:st)
		 a[pos++]=k;
		for(int i=0;i<st.size()-1;i++)
		 d[i]=a[i+1]-a[i];
		sort(d,d+st.size()-1);
		int ans=st.size();
		for(int i=0;i<st.size()-m;i++)
		 ans+=d[i]-1;
		cout<<ans<<endl;
	}
	return 0;
}
