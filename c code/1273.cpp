#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int n;
	while(cin>>n)
	{
		memset(a,0,sizeof a);
		if(n==0) break;
		int i;
		stack<int>st;
		for(i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x]=i;
			a[y]=i;
		}
		st.push(a[1]);
		int j;
		for(j=2;j<=n*2;j++)
		{
			if(st.empty())
			{
				st.push(a[j]);
			}
			else
			{
				if(st.top()==a[j])
				{
					st.pop();
				}
				else
				{
					st.push(a[j]);
				}
			}
		}
		if(st.empty())
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
