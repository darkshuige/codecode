#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
set<pair<double,double> >st;
signed main()
{
    jiasu;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	st.insert({x-0.5,y});
    	st.insert({x+0.5,y});
    	st.insert({x,y-0.5});
    	st.insert({x,y+0.5});
	}
	cout<<st.size()<<endl;
    return 0;
}
