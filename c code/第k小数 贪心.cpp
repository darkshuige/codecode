#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
int a[maxn];
signed main()
{
	jiasu;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		a[op]++;
	}
	int pos=0;
	int cnt=0;
	int gs=0;
	int flag=0;
	if(n>=k)
	{
		flag=1;
		while(a[pos]==0)
		 pos++;
		while(cnt<k)
		{
			cnt++;
			gs++;
			if(gs>a[pos])
			 gs-=a[pos++];
			while(a[pos]==0)
			 pos++;
		}	
	}
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		if(op==2)
		{
			if(flag==-1)
			 cout<<-1<<endl;
			else
			 cout<<pos<<endl;
		}
		else if(op==1)
		{
			int x;
			cin>>x;
			a[x]++;
			n++;
			if(flag==0)
			{
				if(n>=k)
				{
					flag=1;
					pos=0;
					while(!a[pos])
					 pos++;
					cnt=0;
					gs=0;
					while(cnt<k)
					{
						cnt++;
						gs++;
						if(gs>a[pos])
						 gs-=a[pos++];
						while(a[pos]==0)
						 pos++;
					}	
				}
			}
			else
			{
				if(x>=pos)
				{
				}
				else
				{
					gs--;
					while(gs==0)
					{
						pos--;
						gs=a[pos];	
					}	
				}	
			}
		}
	}
	return 0;
} 
