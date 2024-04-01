#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int pre[2000];
int ismirror=0;
void solve(int root,int tail)
{
	if(root>tail) return;
	int i=root+1,j=tail;
	if(!ismirror)
	{
		while(pre[i]<pre[root] && i<=tail)i++;
		while(pre[j]>=pre[root] && j>root) j--;
	}
	else
	{
		while(i<=tail && pre[i]>=pre[root]) i++;
		while(j>root && pre[j]<pre[root]) j--;
	}
	solve(root+1,i-1);
	solve(j+1,tail);
	v.push_back(pre[root]);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>pre[i];
	solve(0,n-1);
	if(v.size()!=n)
	{
		v.clear();
		ismirror=1;
		solve(0,n-1);
	}
	if(v.size()!=n)
	 cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(int i=0;i<v.size();i++)
		{
            if(i!=0)cout<<" ";
            cout<<v[i];
        }
        cout<<endl;
	}
	return 0;
}
