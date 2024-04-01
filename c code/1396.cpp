#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		queue<int>a;
		multiset<int,greater<int> >b;
		int x,n;
		scanf("%d %d",&n,&x);
		for(int j=0;j<n;j++)
		{
			int p;
			scanf("%d",&p);
			a.push(p);
			b.insert(p);
			if(j==x)
			 a.push(-1);
		}
		int count=0;
		while(1)
		{
			if(a.front()==*b.begin())
			{
				count++;
				a.pop();
				b.erase(b.begin());
				if(a.front()==-1)
				 break;
			}
			else
			{
				a.push(a.front());
				a.pop();
			}
		}
		printf("%d\n",count);
	}	
	return 0;	
} 
