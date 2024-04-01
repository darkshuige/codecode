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
	cout<<0<<endl;
	for(int i=0;i<n-1;i++)
	{
		while(!de.empty() && a[i]<=a[de.back()]) de.pop_back();//不空并且要进来的比右边的小就一直pop
		de.push_back(i);//存的都是下标,便于判断
		if(de.front()<i-m+1) de.pop_front();
		cout<<a[de.front()]<<endl;
	}
	return 0;
}


//for(int i=1;i<=n;i++)
//{
//	while(t<=w && a[i]<=a[p[w]])//尾部pop 
//	 w--;
//	p[++w]=i;//尾部push 
//	if(p[t]<i-k+1) //头部pop 
//	 t++;
//	if(i>=k)
//	 cout<<a[p[t]]<<" ";
//}