#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=100005;
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a);
		a=(a*a);
		b>>=1;
	}
	return ans;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int cnt1=0,cnt2=0;
	int a=n;
	while(n)
	{
		if(n%2==1)
		 cnt1++;
		cnt2++;
		n/=2;
	}
	string s="";
	s+='1';
	cnt1--;
	for(int i=0;i<cnt2-cnt1-1;i++)
	 s+='0';
	for(int i=0;i<cnt1;i++)
	 s+='1';
	int sum=0;
	int k=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='1')
		 sum+=ksm(2,k);
		k++;
	}
	cout<<a-sum<<endl;
	return 0;
} 
