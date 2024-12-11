#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=40005;
int flag=0;
vector<int>pre,post;
void f(int root,int tail)
{
	if(root>tail) return ;
	int i=root+1,j=tail;
	if(flag==0)
	{
		while(pre[i]<pre[root] && i<=tail) i++;
		while(pre[j]>=pre[root] && j>root) j--;	
	}
	else
	{
		while(pre[i]>=pre[root] && i<=tail) i++;
		while(pre[j]<pre[root] && j>root) j--;	
	}
	if(i-j!=1) return ;
	f(root+1,j);
	f(i,tail);
	post.push_back(pre[root]);
}
signed main()
{
	jiasu;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int k; cin>>k;
		pre.push_back(k);
	}
	f(0,n-1);
	if(post.size()!=n)
	{
		post.clear();
		flag=1;
		f(0,n-1);
	}
	if(post.size()!=n)
	 cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(int k=0;k<post.size();k++)
		{
			if(k!=0) cout<<" ";
			cout<<post[k];
		}
		cout<<endl;
	}
	return 0;
} 
