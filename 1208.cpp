#include<bits/stdc++.h>
using namespace std;
int cmp1(const int a,const int b)
{
	return a<b;
}
int cmp2(const int a,const int b)
{
	return a>b;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int a[1005]={0},b[1005]={0},c[1005]={0};
		int flag1=1,flag2=1,flag3=1;
		queue<int>q;
		stack<int>st;
		int i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			q.push(a[i]);
			st.push(a[i]);	
			c[i]=a[i];
		}
		for(i=0;i<n;i++)
		 cin>>b[i];
		sort(c,c+n,cmp1);
		for(i=0;i<n;i++)
		{
			if(c[i]!=b[i])
			{
				flag2=0;
				break;
			}
		}
		if(flag2==0)
		{
			flag2=1;
			sort(c,c+n,cmp2);
			for(i=0;i<n;i++)
			{
				if(c[i]!=b[i])
				{
					flag2=0;
					break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			c[i]=q.front();
			q.pop();
			if(c[i]!=b[i])
			{
				flag1=0;
			}
			c[i]=st.top();
			st.pop();
			if(c[i]!=b[i])
			{
				flag3=0;
			}
		}
		int count=0;
		if(flag3)
		{
			cout<<"stack";
			count++;
		}
		if(flag1)
		{
			if(count!=0)
			{
				cout<<" ";
			}
			cout<<"queue";
			count++;
		}
		if(flag2)
		{
			if(count!=0)
			{
				cout<<" ";
			}
			cout<<"priority_queue";
			count++;
		}
		if(flag1==0 && flag2==0 && flag3==0)
		 cout<<"none";
		cout<<endl;
	}
	return 0;
}
