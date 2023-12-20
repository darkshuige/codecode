#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	queue<int>q,wc;
	cin>>n;
	int maxn=INT_MIN;
	for(int i=2;i<=sqrt(n);i++)
	{
		int sum=1;
		int count=0;
		while(q.size())
		 q.pop();
		for(int j=i;j<=sqrt(n);j++)
		{
			if(n%j==0)
			{
				q.push(j);
				count++;
				sum*=j;
				if(count>maxn && n%sum==0 && sum!=1)
				{
					maxn=count;	
					wc=q;
				}
			}
			else
			{
				sum=1;
				count=0;
				while(q.size())
				 q.pop();
				break;
			}	
		}
	}
	if(maxn==INT_MIN)
	{
		cout<<1<<endl;
		cout<<n<<endl;
		return 0;
	}
	cout<<maxn<<endl;
	int count=0;
	int i;
	while(wc.size())
	{
		if(count!=0)
		 cout<<"*";
		i=wc.front();
		cout<<i;
		count++;
		wc.pop();
	}
	cout<<endl;
	return 0;
}
