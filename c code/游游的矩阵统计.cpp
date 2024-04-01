#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn];
int c[maxn],d[maxn];
map<int,int>mp;
signed main()
{
	jiasu;
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)
	 cin>>a[i]>>b[i];
	for(int i=0;i<m2;i++)
	 cin>>c[i]>>d[i];
	int ans=0,i=0,j=0;
	while(i<m1 || j<m2)
	{
		mp[a[i]]++;
		mp[c[j]]++;
		if(i!=0 && mp.size()==2)//当前只有两个颜色 
		 ans++;
		if(a[i]==c[j])//相同的情况下 
		{
			int k=min(b[i],d[j]);
			b[i]-=k;
			d[j]-=k;//约掉 
		}
		else if(a[i]!=c[j])//不同 
		{
			int k=min(b[i],d[j]);
			b[i]-=k;
			d[j]-=k;//约掉
			ans+=k-1;//因为一开始加了一个了 
		}
		mp.clear();
        mp[a[i]]++;
        mp[c[j]]++; 
        if(b[i]==0)
		 i++;
        if(d[j]==0)
		 j++;
	}
	cout<<ans<<endl;
	return 0;
}
 
