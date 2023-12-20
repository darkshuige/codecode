#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int a[210]={0},b[210]={0};
		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			a[k]++;
			b[i]=k;
		}
		for(int i=0;i<n;i++)
		{
			if(a[b[i]]-1==0)
			{
				cout<<"BeiJu"<<endl;
			}
			else
			{
				cout<<a[b[i]]-1<<endl;
			}
		}
	}
	return 0;
}
