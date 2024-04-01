#include<bits/stdc++.h>
using namespace std;
int f[1005],n,m;
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
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
		 break;
		init();
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			add(a,b);
		}
		int op=find(1);
		int flag=1;
		for(int i=1;i<=n;i++)
		 if(find(i)!=op)
		  flag=0;
		if(flag)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
} 
