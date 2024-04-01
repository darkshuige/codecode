#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
char a[10][10],b[10][10],c[10][10],d[20][20];
int flag;
void dfs1(int i,int j,int k)
{
	if(k==0)//0
	{
		
	}
	else if(k==1)//90
	{
		
	}
	else if(k==2)//180
	{
		
	}
	else if(k==3)//270
	{
		
	}
}
signed main()
{
	jiasu;
	for(int i=0;i<4;i++)
	 cin>>a[i];
	for(int i=0;i<4;i++)
	 cin>>b[i];
	for(int i=0;i<4;i++)
	 cin>>c[i];
	flag=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)//确定第一个的位置 
		{
			for(int k=0;k<4;k++)
			{
				memset(d,0,sizeof d);
				dfs1(i,j,k);
				if(flag==1)
				{
					cout<<"Yes"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
