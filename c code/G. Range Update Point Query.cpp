#include<bits/stdc++.h>
using namespace std;
set<int>st;
int f(int x)
{
	int sum=0;
	while(x)
	{
		sum+=x%10;
		x/=10;
	}
	return sum;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,q;
		cin>>n>>q;
		int a[200005];
		st.clear();
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			if(a[j]>9)
			 st.insert(j);
		}
		for(int j=0;j<q;j++)
		{
			int op;
			cin>>op;
			if(op==1)
			{
				int l,r;
				cin>>l>>r;
				int num=l;
				while(!st.empty())
				{
					auto x=st.lower_bound(num);
					if(x==st.end() || *x>r)
					 break;
					a[*x]=f(a[*x]);
					int p=*x;
					st.erase(x);
					if(a[p]>9)
					 st.insert(p);
					num=p+1;
				}
			}
			else
			{
				int x;
				cin>>x;
				cout<<a[x]<<endl;
			}
		}
	}
    return 0;
}
