#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int p[maxn],r[maxn];
int find(int x)
{
	if(p[x]!=x)
	 p[x]=find(p[x]);
	return p[x];
}
int main()
{
	int t;
	while(cin>>t)
	{
		for(int i=0;i<t;i++)
		{
			map<string,int>mp;
			int n;
			cin>>n;
			for(int l=1;l<=2*n;l++)
			{
				p[l]=l;
				r[l]=1;	
			}
		 	int k=1;
			for(int j=1;j<=n;j++)
			{
				string a,b;
				cin>>a>>b;
				if(!mp[a])
				 mp[a]=k++;
				if(!mp[b])
				 mp[b]=k++;
				int x=mp[a],y=mp[b];
				x=find(x);
				y=find(y);
				if(x!=y)
				{
					r[y]+=r[x];
					p[x]=y;
				}
				cout<<r[y]<<endl;
			}	
		}	
	}	
	return 0;
} 
