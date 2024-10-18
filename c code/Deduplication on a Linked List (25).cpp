#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
int root;
vector<int>son[maxn];
int ans[maxn];
bool isf[maxn];
map<string,int>mp;
map<int,string>mp1;
vector<int>ans1,ans2;
void dfs(int now)
{
	if(now==-1) return ;
	if(isf[abs(ans[now])]==0)
	{
		isf[abs(ans[now])]=1;
		ans1.push_back(now);
	}
	else
	 ans2.push_back(now);
	for(auto k:son[now])
	 dfs(k);
}
signed main()
{
    int n;
    string s;
    while(cin>>s>>n)
    {
    	for(int i=0;i<=n;i++) son[i].clear();
    	ans1.clear(),ans2.clear();
    	memset(isf,0,sizeof isf);
    	mp[s]=0;
    	mp1[0]=s;
    	int k=1;
    	for(int i=1;i<=n;i++)
    	{
    		string s1,s2;
    		int kk;
    		cin>>s1>>kk>>s2;
    		if(!mp[s1])
			{
				mp[s1]=k;
				mp1[k++]=s1;
			} 
    		ans[mp[s1]]=kk;
    		if(!mp[s2] && s2!="-1")
			{
				mp[s2]=k;
				mp1[k++]=s2;
			} 
    		if(s2!="-1")
    		 son[mp[s1]].push_back(mp[s2]);
    		else
    		 son[mp[s1]].push_back(-1); 
		}
		dfs(mp[s]);
		for(int k=0,num=ans1.size();k<num;k++)
		{
			if(k!=num-1)
			 cout<<mp1[ans1[k]]<<" "<<ans[ans1[k]]<<" "<<mp1[ans1[k+1]]<<endl;
			else
			 cout<<mp1[ans1[k]]<<" "<<ans[ans1[k]]<<" "<<-1<<endl;
		}
		for(int k=0,num=ans2.size();k<num;k++)
		{
			if(k!=num-1)
			 cout<<mp1[ans2[k]]<<" "<<ans[ans2[k]]<<" "<<mp1[ans2[k+1]]<<endl;
			else
			 cout<<mp1[ans2[k]]<<" "<<ans[ans2[k]]<<" "<<-1<<endl;
		}
	}
    return 0;
}
