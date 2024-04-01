#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		multiset<int,greater<int> >st;
		queue<int>q;
		int n,k;
		cin>>n>>k;
		for(int j=0;j<n;j++)
		{
			int op;
			cin>>op;
			q.push(op);
			if(j==k)
			 q.push(-1);
			st.insert(op);
		}
		int count=0;
		while(1)
		{
			int op=q.front();
			if(op==*st.begin())
			{
				count++;
				q.pop();
				if(q.front()==-1)
			     break;
				st.erase(st.begin());
			}
			else
			{
				q.pop();
				q.push(op);
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
