#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=2010;
struct node
{
	double l,r;
}a[maxn];
int cmp(node a,node b)
{
	if(a.l!=b.l)
	 return a.l<b.l;
	else
	 return a.r<b.r;
}
signed main()
{
    jiasu;
    int n;
    int c=1;
    double d;
    while(cin>>n>>d)
    {
    	if(n==0 && d==0)
    	 break;
    	int pos=0;
    	int flag=1;
    	double x,y;
    	for(int i=0;i<n;i++)
    	{
	    	cin>>x>>y;
	    	if(y>d) flag=0;
	    	double len=sqrt(pow(d,2)-pow(y,2));
	    	a[pos].l=x-len;
	    	a[pos++].r=x+len;	
		}
    	int ans=1;
    	sort(a,a+pos,cmp);
    	double l=a[0].l,r=a[0].r;
    	for(int i=1;i<pos;i++)
    	{
    		if(a[i].r<r)
    		{
    			l=a[i].l;
    			r=a[i].r;
			}
    		if(a[i].r>r && a[i].l<=r)
    		{
    			l=a[i].l;
			}
			else if(a[i].l>r)
			{
				ans++;
				l=a[i].l;
				r=a[i].r;
			}
		}
		cout<<"Case "<<c<<": ";
		if(flag)
		 cout<<ans<<endl;
		else
		 cout<<-1<<endl;
		c++;
	}
    return 0;
}
