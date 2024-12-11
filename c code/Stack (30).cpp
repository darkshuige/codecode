#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
stack<int>sta;
multiset<int>st;
signed main()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		if(s=="Push")
		{
			int k; cin>>k;
			sta.push(k);
			st.insert(k);
		}
		else if(s=="Pop")
		{
			if(sta.size()==0) cout<<"Invalid"<<endl;
			else
			{
				cout<<sta.top()<<endl;
				st.erase(st.find(sta.top()));
				sta.pop();
			}
		}
		else
		{
			if(sta.size()!=0)
			{
				int m=sta.size();
				if(m%2!=0)
				m++;
				m/=2;
				auto it=st.begin();
				for(int i=0;i<m-1;i++) it++;
				cout<<*it<<endl;
			}
			else cout<<"Invalid"<<endl;
		}
	}
    return 0;
}