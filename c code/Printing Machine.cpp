#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=400005;
pair<int,int>a[maxn];
signed main() 
{
    jiasu;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
     cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    priority_queue<int,vector<int>,greater<int> >q;
    int ans=0;
    for(int i=0;i<n;i++)
    {
    	q.push(a[i].first+a[i].second);
    	while(a[i+1].first==a[i].first && i+1<n)
    	{
    		i++;
    		q.push(a[i].first+a[i].second);
		}
		int bound=i+1<n?a[i+1].first:LLONG_MAX;
		int t=a[i].first;
		while(t<bound && !q.empty())
		{
			int ed=q.top();q.pop();
			if(t<=ed)
			{
				ans++;
				t++;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
