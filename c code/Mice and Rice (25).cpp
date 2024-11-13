#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1005;
int b[maxn];
int w[maxn],rk[maxn];
queue<int>q,temp;
priority_queue<pair<int,int> >pq;
signed main()
{
	int np,ng; cin>>np>>ng;
	for(int i=0;i<np;i++) cin>>w[i];
	for(int i=0;i<np;i++) cin>>b[i];
	for(int i=0;i<np;i++)
	 q.push(b[i]);
	int now=0;
	while(!(q.size()==1))
	{
		queue<int>qq=q;
		while(!temp.empty()) temp.pop();
		while(!qq.empty())
		{
			pq.push({w[qq.front()],qq.front()});
			qq.pop();
			if(pq.size()==ng)
			{
				temp.push(pq.top().second);
				pq.pop();
				while(!pq.empty())
				{
					rk[pq.top().second]=now;
					pq.pop();
				}
			}
		}
		temp.push(pq.top().second);
		pq.pop();
		while(!pq.empty())
		{
			rk[pq.top().second]=now;
			pq.pop();
		}
		now++;
		q=temp;
	}
	rk[q.front()]=now;
	for(int i=0;i<np;i++)
	{
		if(i!=0) cout<<" ";
		if(rk[i]==0) cout<<now+2;
		else
		cout<<now+rk[i];
	}
    return 0;
}