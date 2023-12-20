#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		 break;
		int a[1005]={0};
		int pos=1;
		queue<int>q;
		q.push(pos);
		for(int i=0;i<n;i++)
		{
			int pp=q.front();
			q.pop();
			cin>>a[pp];
			q.push(pp*2);
			q.push(pp*2+1);
		}
		int deep=(log(n)/log(2))+1;
		int k;
		cin>>k;
		if(k>deep)
		 cout<<"EMPTY"<<endl;
		else
		{
			int j=pow(2,k-1);
			int cnt=0;
			for(int i=j;cnt<j;i++)
			{
				if(a[i]!=0)
				{
					if(i!=j)
					 cout<<" ";
					cout<<a[i];
					cnt++;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
