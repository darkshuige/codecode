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
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f
using namespace std;
const int maxn=100005;
int f[maxn],cx[maxn];
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
}
int find(int x)
{
	if(x==f[x])
	 return x;
	else
	 return f[x]=find(f[x]);
}
int flag;
void join(int x,int y)
{
	int ex=find(x);int ey=find(y);
	if(ex!=ey)
	 f[ex]=ey;
	else
	 flag=0;
}
signed main()
{
	jiasu;
	int cnt=1;
	int a,b;
	flag=1;
	init();
	memset(cx,0,sizeof cx);
	int num1=0,num2=0;
	while(cin>>a>>b)
	{
		if(a==-1 && b==-1) break;
		if(a==0 && b==0)
		{
			cout<<"Case "<<cnt<<" is ";
			cnt++;
			if((flag==1 && num1==num2+1) || (num1==num2 && num1==0))
			 cout<<"a tree."<<endl;
			else
			 cout<<"not a tree."<<endl;
			init();num1=0;num2=0;
			memset(cx,0,sizeof cx);
			flag=1;	
		}
		else
		{
			if(cx[a]==0) cx[a]=1,num1++;
			if(cx[b]==0) cx[b]=1,num1++;
			num2++;
			join(a,b);
		} 
	}
	return 0;
}
