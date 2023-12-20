#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=700005;
int a[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=n+1;i<=n*2;i++)
	 a[i]=a[i-n];
	int i=1,j=2,k=0;
	while(i<=n && j<=n)
	{
		for(k=0;k<n && a[i+k]==a[j+k];k++);
		if(a[i+k]<a[j+k])
		 j=j+k+1;
		else
		 i=i+k+1;
		if(i==j)
		 j++;
	}
	int pos=min(i,j);
	for(int i=0;i<n;i++)
	 cout<<a[pos+i]<<" ";
	cout<<endl;
	return 0;
}
