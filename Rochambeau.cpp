#include <iostream>
#include <cstdio>
#include <algorithm>
#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#include<iomanip>
#include<string>
#include<stack>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
using namespace std;
const int maxn =4000;
struct node
{
	int x,y;
	char cmp;
}rd[maxn];
int f[maxn],rela[maxn];
void init()
{
	for(int i=0;i<maxn;i++)
	{
		f[i]=i;
		rela[i]=0;
	}
}
int find(int x)
{
	if(x==f[x]) return x;
	int root=find(f[x]);
	rela[x]+=rela[f[x]],rela[x]%=3;
	return f[x]=root;
}
void join(int x,int y,int r)
{
	int ex=find(x);int ey=find(y);
	if(ex!=ey)
	{
		f[ex]=ey;
		rela[ex]=(r+rela[y]-rela[x]+3)%3;
	}
}
signed main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<m;i++)
		 cin>>rd[i].x>>rd[i].cmp>>rd[i].y;
		int num=0,pos=0,pl=0;
		for(int i=0;i<n;i++)
		{
			init();
			int flag=1;
			for(int j=0;j<m;j++)
			{
				if(rd[j].x==i || rd[j].y==i) continue;
				int ra=find(rd[j].x);int rb=find(rd[j].y);
				int temp;
				if(rd[j].cmp=='>') temp=1;
				else if(rd[j].cmp=='=') temp=0;
				else temp=2;
				if(ra!=rb)
				{
					join(rd[j].x,rd[j].y,temp);
				}
				else if((rela[rd[j].x]-rela[rd[j].y]+3)%3!=temp)
				{
					flag=0;
					pos=max(pos,j+1);
					break;
				}
			}
			if(flag)
			{
				num++;
				pl=i;	
			}
		}
		if(n==1) pos=0;
		if(num>1) cout<<"Can not determine"<<endl;
		else if(num==0) cout<<"Impossible"<<endl;
		else
		{
			cout<<"Player "<<pl<<" can be determined to be the judge after "<<pos<<" lines"<<endl;
		}
	}
    return 0;
}
