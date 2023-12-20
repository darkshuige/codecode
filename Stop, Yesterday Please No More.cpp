#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n,m,k;
string s;
int main()
{
    ios::sync_with_stdio(false);   cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>s;
        int sz = s.size();
        s = "?"+s;
        vector<vector<int>>mp(n+10,vector<int>(m+10));
        vector<vector<int>>vis(n+10,vector<int>(m+10));
        int L = 1,R = m;
        int U = 1,D = n;
        int curL = 1,curR = m;
        int curU = 1,curD = n;
        for(int i = 1;i <= sz; i++)
        {
            if(s[i]=='L')curL++,curR++;
            else if(s[i]=='R')curL--,curR--;
            else if(s[i]=='U')curU++,curD++;
            else if(s[i]=='D')curU--,curD--;
            L = max(L,curL);
            R = min(R,curR);
            U = max(U,curU);
            D = min(D,curD);
        }
        if(L>R||U>D)
		{
            if(k==0)cout<<n*m<<"\n";
            else cout<<0<<"\n";
            continue;
        }
        int x1 = U,y1 = L;
        int x2 = D,y2 = R;
        vis[x1][y1]=1;
        for(int i=x1;i<=x2;i++)
        {
        	mp[i][y1]++;
        	mp[i][y2+1]--;
		}
        for(int i = 1;i <= sz; i++)
		{
            if(s[i]=='L')y1--,y2--;
            else if(s[i]=='R')y1++,y2++;
            else if(s[i]=='U')x1--,x2--;
            else if(s[i]=='D')x1++,x2++;
            vis[x1][y1]=1;
	        for(int i=x1;i<=x2;i++)
	        {
	        	mp[i][y1]++;
	        	mp[i][y2+1]--;
			}
        }
        for(int i = 1;i <= n; i++)
		{
            for(int j = 1;j <= m; j++)
			{
                mp[i][j]=mp[i][j-1]+mp[i][j];
            }
        }
        int cnt = (D-U+1)*(R-L+1),ans = 0;
        int need = cnt-k;
        if(need<0){
            cout<<0<<"\n";
            continue;
        }
        for(int i = 1;i <= n; i++)
		{
            for(int j = 1;j <= m; j++)
			{
                if(need==mp[i][j])ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
