#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int bfs(int n)
{
	queue<int>q;
	q.push(n);
	while(!q.empty())
	{
		int now=q.front(); q.pop();
		if(now%495==0) return now;
		for(int i=0;i<=9;i++)
		{
			int ne=now*10+i;
			q.push(ne);			
		}
	}
	return 0;
}
signed main() 
{
    jiasu;
    int n;
    cin>>n;
    if(n%495==0)
    {
    	cout<<-1<<endl;
    	return 0;
	}
    int orin=n;
    int ok=bfs(n);
    string s=to_string(ok);
    int pos=s.find(to_string(orin));
    cout<<s.substr(pos+to_string(orin).size())<<endl;
    return 0;
}
