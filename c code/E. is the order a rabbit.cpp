#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int maxx[100005];
int main() 
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i];
		maxx[i]=max(a[i],b[i]);
	}
	for(int i=n;i>=1;i--)
	 maxx[i]=max(maxx[i],maxx[i+1]);
	for(int i=1;i<=n;++i)
	{
		if(maxx[i+1]-min(a[i],b[i])>b[i]-a[i])
		 ans+=max(0,maxx[i+1]-min(a[i],b[i]));
		else
		 ans+=max(0,b[i]-a[i]);
	}
	cout<<ans<<endl;
}
