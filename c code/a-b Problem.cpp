#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
struct node
{
	int a,b;
	int pos_a,pos_b;
}a[maxn],b[maxn];;
int cmp1(node a,node b)
{
	return a.a-b.b>b.a-a.b;
}
int cmp2(node a,node b)
{
	return a.b-b.a>b.b-a.a;
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
		for(int i=1;i<=n;i++)
		 cin>>a[i].a>>a[i].b;
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++)
		 a[i].pos_a=i;
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++)
		{
			a[i].pos_b=i;
			b[i]=a[i];
		}
		sort(a+1,a+1+n,cmp1);
		int pos1=1,pos2=1,sum1=0,sum2=0;
		int cnt=0;
		int flag=0;
		while(cnt<n)
		{
			while(a[pos1].a==-1 && a[pos1].b==-1) pos1++;
			while(b[pos2].a==-1 && b[pos2].b==-1) pos2++;
			if(flag==0)
			{
				sum1+=a[pos1].a;
				a[pos1].a=-1,a[pos1].b=-1;
				b[a[pos1].pos_b].a=-1,b[a[pos1].pos_b].b=-1;
				pos1++;
				cnt++;
				flag=1;
			}
			else
			{
				sum2+=b[pos2].b;
				b[pos2].a=-1,b[pos2].b=-1;
				a[b[pos2].pos_a].a=-1,a[b[pos2].pos_a].b=-1;
				pos2++;
				cnt++;
				flag=0;
			}
		}
		cout<<sum1-sum2<<endl;
	}
	return 0;
}
