#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=2000;
struct node
{
	int num,len;
}a[maxn];
int cmp(node a,node b)
{
	if(a.len!=b.len)
	 return a.len>b.len;
	else
	 return a.num<b.num;
}
vector<int>ans;
int f(int n)
{
	int len=0;
	while(n>=10)
	{
		int sum=1;
		int kk=n;
		while(kk)
		{
			sum*=kk%10;
			kk/=10;
		}
		n=sum;
		len++;
	}
	return len;
}
int cnt=0;
signed main()
{
	jiasu;
	int l,r; cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		int ll=f(i);
//		cout<<i<<" "<<ll<<endl;
		a[cnt++]={i,ll};
	}
	sort(a,a+cnt,cmp);
	int len=a[0].len;
	cout<<len<<endl;
	for(int i=0;i<cnt;i++)
	 if(a[i].len==len) ans.push_back(a[i].num);
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)
		 cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}