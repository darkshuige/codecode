#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
int b[maxn],c[maxn];
int l;
void add(int a[])
{
	int ct=0;
	for(int i=l-1;i>=0;i--)
	 c[ct++]=b[i];
	for(int i=0;i<l;i++)
	 b[i]+=c[i];
	for(int i=0;i<l;i++)
	 if(b[i]>=0)
	 {
	 	b[i+1]+=b[i]/10;
	 	b[i]%=10;
	 }
	if(b[l]>0) l++;
}
int f()
{
	int ct=0;
	for(int i=l-1;i>=0;i--)
	 c[ct++]=b[i];
	for(int i=0;i<l;i++)
	 if(b[i]!=c[i]) return 0;
	return 1;
}
signed main()
{
	string s; cin>>s;
	int ct=0;
	for(int i=s.size()-1;i>=0;i--) b[ct++]=s[i]-'0';
	int k; cin>>k;
	int i;
	l=s.size();
	for(i=0;i<k;i++)
	{
		if(f()) break;
		add(b);
	}
	for(int i=l-1;i>=0;i--) cout<<b[i];
	cout<<endl;
	cout<<i<<endl;
	return 0;
} 