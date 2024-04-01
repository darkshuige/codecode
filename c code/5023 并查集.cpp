#include<bits/stdc++.h>
using namespace std;
int parent[200],r[200];
int find(int x)
{
	if(parent[x]==x)
	 return x;
	else
	 return x=find(parent[x]);//Â·¾¶Ñ¹Ëõ 
}
void join(int x,int y)
{
	int rx=find(x);
	int ry=find(y);
	if(rx!=ry)
	{
		parent[ry]=rx;
		r[rx]+=r[ry];
	}
}
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			parent[i]=i;
			r[i]=1;
		}
		for(int i=0;i<k;i++)
		{
			int a,b;
			cin>>a>>b;
			join(a,b);
		}
		set<int>st;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,r[i]);
			st.insert(find(i));
		}
		cout<<st.size()<<" "<<maxn<<endl;	
	}
	
	return 0;
}
