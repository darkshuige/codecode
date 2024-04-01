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
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
//#define int long long
using namespace std;
const int maxn=300000 + 50;
int n,m,k;
int x,y,z;
int a,b,c;
string s,t;
char op;
struct ran
{
	int x,y,z;
	char op;
}tr[maxn];
int f[maxn],dix[maxn],diy[maxn];
int find(int x)
{
	if(x==f[x]) return x;
    int root=find(f[x]);
    dix[x]+=dix[f[x]];
    diy[x]+=diy[f[x]];
    return f[x]=root;
}
void join(int x,int y,int dx,int dy)
{
	int ex=find(x);int ey=find(y);
	f[ex]=ey;
	dix[ex]=dix[y]-dix[x]+dx;
	diy[ex]=diy[y]-diy[x]+dy;
}
signed main() 
{
    jiasu;
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i,dix[i]=0,diy[i]=0;
    for(int i=1;i<=m;i++) cin>>tr[i].x>>tr[i].y>>tr[i].z>>tr[i].op;
	int pos=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		for(int j=pos;j<=c;j++)
		{
			int dx=0,dy=0;
			if(tr[j].op == 'E') dx = tr[j].z;
            else if(tr[j].op == 'W') dx = -tr[j].z;
            else if(tr[j].op == 'N') dy = tr[j].z;
            else dy = -tr[j].z;
            join(tr[j].x,tr[j].y,dx,dy);
		}
		pos=c+1;
		int ex=find(a);int ey=find(b);
		if(ex!=ey)
		 cout<<-1<<endl;
		else
		 cout<<abs(dix[a]-dix[b])+abs(diy[a]-diy[b])<<endl;
	}
    return 0;
}
