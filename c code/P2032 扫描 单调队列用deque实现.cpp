#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000005;
int a[maxn];
deque<int>de;
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		while(!de.empty() && a[i]>=a[de.back()]) de.pop_back();//不空并且要进来的比右边的小就一直pop
		de.push_back(i);//存的都是下标,便于判断
		if(de.front()<i-m+1) de.pop_front();
		if(i+1>=m)
		 cout<<a[de.front()]<<endl;
	}
	return 0;
}
