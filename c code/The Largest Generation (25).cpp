#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
int root;
vector<int>son[maxn];
int ans[maxn];
bool isf[maxn];
int ma=0;
void dfs(int now,int deep)
{
	ans[deep]++;
    if(ans[deep]>ans[ma]) ma=deep;
    for(int k:son[now])
     dfs(k,deep+1);
}
signed main()
{
    int n;
    while(cin>>n)
    {
    	memset(isf,0,sizeof isf);
    	memset(ans,0,sizeof ans);
    	int m; cin>>m;
    	while(m--)
    	{
    		int f; cin>>f;
    		int k; cin>>k;
    		for(int i=0;i<k;i++)
    		{
    			int kk; cin>>kk;
    			son[f].push_back(kk);
    			isf[kk]=1;
			}
		}
		for(int i=1;i<=n;i++)
		 if(isf[i]==0)
		  dfs(i,1);
		cout<<ans[ma]<<" "<<ma<<endl;
	}
    return 0;
}
