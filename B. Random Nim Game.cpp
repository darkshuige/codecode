	#include<bits/stdc++.h>
	#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
	#define int long long
	#define endl "\n"
	using namespace std;
	signed main()
	{
		jiasu;
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			int sum=0;
			set<int>st;
			for(int i=0;i<n;i++)
			{
				int op;
				cin>>op;
				if(op==1)
				 sum++;
				st.insert(op);
			}
			if(st.size()==1 && *st.begin()==1)
			{
				cout<<sum%2<<endl;
			}
			else
			{
				cout<<"499122177"<<endl;
			}
		} 
		return 0;
	}
