#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=400005;
struct node
{
	int dl,val;
}a[maxn];
int cmp(node a,node b)
{
	if(a.val!=b.val)
	 return a.val>b.val;
	else 
	 return a.dl>b.dl;
}
int f[maxn];
void init()
{
	memset(f,-1,sizeof f);
}
int find(int x)
{
	if(f[x]==-1)
	 return x;
	else
	 return f[x]=find(f[x]);
}
signed main() 
{
    int n;
    while(cin>>n)
    {
    	init();
    	for(int i=0;i<n;i++)
    	 cin>>a[i].val>>a[i].dl;
    	sort(a,a+n,cmp);
    	int ans=0;
    	for(int i=0;i<n;i++)
    	{
    		int t=find(a[i].dl);
    		if(t>0)
    		{
    			ans+=a[i].val;
    			f[t]=t-1;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
