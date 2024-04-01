#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		 break;
		stack<int>st;
		char op;
		for(int i=0;i<n;i++)
		{
			cin>>op;
			if(op=='P')
			{
				int a;
				cin>>a;
				st.push(a);
			}
			else if(op=='O')
			{
				if(!st.empty())
				 st.pop();	
			}
			else if(op=='A')
			{
				if(!st.empty())
				 cout<<st.top()<<endl;
				else
				 cout<<"E"<<endl;
			}	
		}
		cout<<endl;
	}
	return 0;
}
