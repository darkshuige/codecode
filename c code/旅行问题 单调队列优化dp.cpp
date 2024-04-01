#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
int a[maxn],b[maxn],c[maxn],d[maxn],s1[maxn],s2[maxn];
int flag[maxn];
deque<int>de;
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)	
	 cin>>a[i]>>b[i];
	a[0]=a[n],b[0]=b[n];
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i]-b[i];
		d[i]=a[i]-b[i-1];
	}
	for(int i=1;i<=n;i++)
	 c[i+n]=c[i],d[i+n]=d[i];//断链成环
	for(int i=1;i<=2*n;i++)
	 s1[i]+=s1[i-1]+c[i];//前缀和
	for(int i=2*n;i>=1;i--)
	 s2[i]+=s2[i+1]+d[i];//后缀和
	memset(flag,0,sizeof flag);
	for(int i=n*2;i>=0;i--)
	{
		while(!de.empty() && s1[de.front()]>s1[i+1]) de.pop_front();
		de.push_front(i+1);
		if(de.back()>i+n) de.pop_back();
		if(s1[de.back()]-s1[i]>=0) flag[i+1]=1;
	}
	de.clear();
	for(int i=2;i<=2*n;i++)
	{
		while(!de.empty() && s2[de.back()]>s2[i-1]) de.pop_back();
		de.push_back(i-1);
		if(de.front()<i-n) de.pop_front();
		if(s2[de.front()]-s2[i]>=0) flag[i-1]=1;
	}
	for(int i=1;i<=n;i++)
	 if(flag[i])
	  cout<<"TAK"<<endl;
	 else
	  cout<<"NIE"<<endl;
	return 0;
}