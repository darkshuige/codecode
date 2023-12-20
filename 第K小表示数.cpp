#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=5000005;
double PI=acos(-1);
set<int>st,a,b;
signed main()
{
	jiasu;
	int k,aa,bb;
	cin>>k>>aa>>bb;
	int p1=1,p2=1;
	if(aa>bb) swap(aa,bb);
	a.insert(aa),b.insert(bb);
	if(k==1)
	{
		cout<<min(aa,bb)<<endl;
		return 0;
	}
	else if(k==2)
	{
		cout<<max(aa,bb)<<endl;
		return 0;
	}
	st.insert(aa);st.insert(bb);
	while(st.size()!=k)
	{
		st.insert(*a.begin()*2);
		if(st.size()==k) break;
		int x,y;
		int kk=0;
		for(auto pos=a.begin();kk<p1;pos++,kk++)
		 x=*pos;
		for(auto pos=b.begin();pos!=b.end();pos++)
		{
			st.insert(x+*pos);
			if(st.size()==k) break;		
		}
		if(st.size()==k) break;
		p1++;
		st.insert(*b.begin()*2);
		if(st.size()==k) break;
		kk=0;
		for(auto pos=b.begin();kk<p2;pos++)
		 y=*pos;
		for(auto pos=a.begin();pos!=a.end();pos++,kk++)
		{
			st.insert(y+*pos);
			if(st.size()==k) break;		
		}
		if(st.size()==k) break;
	}
	cout<<*st.rbegin()<<endl;
	return 0;
}
