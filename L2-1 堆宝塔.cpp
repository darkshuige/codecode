#include<bits/stdc++.h>
using namespace std;
stack<int>a,b;
int main()
{
	int n;
	cin>>n;
	int maxn=INT_MIN;
	int count=0;
	int count1=0,count2=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(a.empty())
		{
			a.push(x);
			count1++;
		}
		else if(x<a.top())
		{
			a.push(x);
			count1++;
		}
		else if(x>=a.top() && b.empty())
		{
			b.push(x);
			count2++;
		}
		else if(x>=a.top() && !b.empty() && x>b.top())
		{
			b.push(x);
			count2++;
		}
		else
		{
			count++;
			if(count1>maxn)
			 maxn=count1;
			while(!a.empty())
			{
				a.pop();
				count1--;	
			}
			while(b.top()>x && !b.empty())
			{
				a.push(b.top());
				count1++;
				b.pop();
				count2--;
			}
			a.push(x);
			count1++;
		}
	}
	if(!a.empty())
	 count++;
	if(!b.empty())
	 count++;
	if(count1>maxn) maxn=count1;
	if(count2>maxn) maxn=count2;
	cout<<count<<" "<<maxn<<endl;
	return 0;
} 
