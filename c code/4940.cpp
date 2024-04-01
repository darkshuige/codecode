#include<bits/stdc++.h>
using namespace std;
int n,f[1010],m;
void init()
{
	for(int i=1;i<=n;i++)
	 f[i]=i;
}
int find(int x)
{
	if(f[x]==x)
	 return x;
	else
	 return x=find(f[x]);
}
void add(int x,int y)
{
	int rx=find(x),ry=find(y);
	f[ry]=rx;
}
int main()
{
	while(cin>>n)
	{
		if(n==0)
		 break;
		init();
		cin>>m;
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			add(a,b);
		}
		set<int>st;
		for(int i=1;i<=n;i++)
		 st.insert(find(i));
		cout<<st.size()-1<<endl;
	}
	return 0;
}
