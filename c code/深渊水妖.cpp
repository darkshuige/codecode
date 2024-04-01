#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	vector<int>v;
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		memset(a,0,sizeof a);
		int n,j,k;
		cin>>n;
		for(j=1;j<=n;j++)
		 cin>>a[j];
		int maxn=INT_MIN;
		int maxl=INT_MIN;
		for(j=1;j<n;j+=k-1)
		{
			k=j+1;
			while(a[k]>=a[k-1])
			{
				if(k-j>maxl)
				{
					v.clear();
					v.push_back(j);
					v.push_back(k);
					maxl=k-j;
					maxn=a[k]-a[j];
				}
				else if(k-j==maxl)
				{
					if(a[k]-a[j]>maxn)
					{
						v.clear();
						v.push_back(j);
						v.push_back(k);
						maxn=a[k]-a[j];
					}
					else if(a[k]-a[j]==maxn)
					{
						v.push_back(j);
						v.push_back(k);
					}
				}
				k++;
			}
		}
		vector<int>::iterator it;
		for(it=v.begin();it!=v.end();it++)
		{
			if(it!=v.begin())
			{
				cout<<" ";
			}
			cout<<*it;
		}
		cout<<endl;
		v.clear();
	}
	return 0;
}
