#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
string st,ed;
int len;
stack<char>sta;
vector<char>ans;
void dfs(int i,int j)
{
	if(i==len && j==len)
	{
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	if(i<len)
	{
		sta.push(st[i]);
		ans.push_back('i');
		dfs(i+1,j);
		sta.pop();
		ans.pop_back();
	}
	if(j<len && j<i && sta.top()==ed[j])
	{
		char tmp=sta.top();
		sta.pop();
		ans.push_back('o');
		dfs(i,j+1);
		sta.push(tmp);
		ans.pop_back();
	}
}
signed main()
{
	while(cin>>st>>ed)
	{
		len=st.size();
		ans.clear();
		while(!sta.empty()) sta.pop();
		cout<<"["<<endl;
		dfs(0,0);
		cout<<"]"<<endl;
	}
	return 0;
} 
