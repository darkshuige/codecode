#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000005;
struct node
{
	int r,c;
}a[maxn],b[maxn];
int cmp(node a,node b)
{
	return a.c<b.c;
}
signed main() 
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int cnt1=0,cnt2=0,flag=0;
		for(int i=0;i<n;i++)
		{
			int r,c;
			cin>>r>>c;
			if(c==0) flag=1;
			else if(c<0)
			 a[cnt1++]={r,c};
			else
			 b[cnt2++]={r,c};
		}
		int flag1=0,flag2=0;
		sort(a,a+cnt1,cmp);sort(b,b+cnt2,cmp);
		if(cnt1!=0) flag1=1; if(cnt2!=0) flag2=1;
		for(int i=1;i<cnt1;i++)
		{
			if(a[i-1].r!=a[i].r && abs(a[i-1].c-a[i].c)<=1)
			{
				flag1=2;
				break;	
			}
		}
		for(int i=1;i<cnt2;i++)
		{
			if(b[i-1].r!=b[i].r && abs(b[i-1].c-b[i].c)<=1)
			{
				flag2=2;
				break;
			}
		}
		int le=0,ri=0;
		if(flag)
		{
			if(flag1==2)
			 le=0;
			else if(flag1==1 && a[cnt1-1].r==1 && a[cnt1-1].c==-1)
			 le=0;
			else if(flag1==0)
			 le=1;
			if(flag2==2)
			 ri=0;
			else if(flag2==1 && b[0].r==1 && b[0].c==1)
			 ri=0;
			else if(flag2==0)
			 ri=1;
		}
		else
		{
			if(flag1==2)
			 le=0;
			else if(flag1==1)
			{
				if(a[cnt1-1].r==1 && a[cnt1-1].c==-1)
				{
					le=1;
					flag=1;	
				}
				else
				{
					le=1;
				}
			}
			else if(flag1==0)
			{
				le=2;
				flag=1;
			}
			if(flag2==2)
			 ri=0;
			else if(flag2==1)
			{
				if(flag)
				{
					if(b[0].r==1 && b[0].c==1)
					 ri=0;
					else
					 ri=1;
				}
				else
				{
					ri=1;
				}
			}
			else if(flag2==0)
			{
				if(flag)
				 ri=1;
				else
				 ri=2;
			}
		}
		cout<<le+ri<<endl;
	}
    return 0;
}

