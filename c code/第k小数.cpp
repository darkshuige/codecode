#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=200009;
int a[maxn];
signed main()
{
	jiasu;
	int n,m,k;
	cin>>n>>m>>k;
	multiset<int,greater<int> >st;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	for(int i=0;i<k && i<n;i++)
	 st.insert(a[i]);
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			cin>>x;
			if(st.size()<k)
			{
				st.insert(x);
			}
			else
			{
				if(x<*st.begin())
				{
					st.erase(st.begin());
					st.insert(x);
				}
			}
		}
		else
		{
			if(st.size()<k)
			 cout<<-1<<endl;
			else
			 cout<<*st.begin()<<endl;
		}
	}
	return 0;
} 
