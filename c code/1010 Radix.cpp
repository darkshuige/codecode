#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
int f(char k)
{
	int ans;
	if(k>='0' && k<='9')
	 ans=k-'0';
	else
	{
		ans=k-'a';
		ans+=10;
	}
	return ans;
}
int ksm(int a,int n)
{
	int ans=1;
	while(n)
	{
		if(n & 1)
		 ans*=a;
		a*=a;
		n>>=1;
	}
	return ans;
}
int ff(string a,int b)
{
	int ans=0;
	int cnt=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		ans+=(f(a[i])*ksm(b,cnt));
		cnt++;
	}
	return ans;
}
int getma(string s)
{
	int ma=-1;
	for(int i=0;i<s.size();i++)
	{
		int num=f(s[i]);
		ma=max(ma,num);
	}
	return ma;
}
signed main()
{
	string n1,n2; cin>>n1>>n2;
	int tag,rad; cin>>tag>>rad;
	if(tag==2) swap(n1,n2);//a1一定是要的
	int cnt=0;
	int sum=0;
	for(int i=n1.size()-1;i>=0;i--)
	{
		sum+=f(n1[i])*ksm(rad,cnt);
		cnt++;
	}
	int l=getma(n2)+1,r=max(l,sum+1),aannss=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		int now=ff(n2,mid);
		if(now>=sum || now<0)
		{
			if(now==sum)
			 aannss=mid;
			r=mid-1;
		}
		else if(now<sum)
		{
			l=mid+1;
		}
	}
	if(aannss!=-1)
	 cout<<aannss<<endl;
	else
	 cout<<"Impossible"<<endl;
	return 0;
} 