#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		queue<int>q,qq;
		int count=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			qq=q;
			int flag=0;
			while(!qq.empty())
			{
				if(qq.front()==x)
				{
					flag=1;
					break;
				}
				qq.pop();
			}
			if(flag==0)
			{
				if(q.size()<m)
				{
					count++;
					q.push(x);
				}
				else if(q.size()>=m)
				{
					q.pop();
					count++;
					q.push(x);
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
