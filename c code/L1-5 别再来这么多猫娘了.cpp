#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200;
struct node
{
	string s;
}a[maxn];
int cmp(node a,node b)
{
	return a.s.size()<b.s.size();
}
signed main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;
	}
	sort(a+1,a+1+n,cmp);
	int k; cin>>k;
	getchar();
	string ans;
	char c;
	int sum=0;
	c=getchar();
	while(c!='\n')
	{
		ans+=c;
		for(int i=1;i<=n;i++)
		{
			int pos=ans.find(a[i].s);
			if(pos!=string::npos)
			{
				sum++;
				ans.erase(pos,a[i].s.size());
				ans.insert(pos,"<censored>");
			}
		}
		c=getchar();
	}
	
	if(sum<k)
	 cout<<ans<<endl;
	else
	{
		cout<<sum<<endl;
		cout<<"He Xie Ni Quan Jia!"<<endl;
	}
	return 0;
}