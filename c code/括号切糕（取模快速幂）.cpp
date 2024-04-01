#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
const int mod=1e9+7;
using namespace std;
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
signed main()
{
	jiasu;
	string a;
	cin>>a;
	int sum1=0,sum2=0,sum=0,flag=1;
	if(a.size()%2==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='(')
		{
			sum1++;
		}
		else if(a[i]==')')
		{
			if(sum1==0)
			{
				flag=0;
			}
			else if(sum1>0)
			{ 
				sum1--;
			}
		}
		if(sum1==0 && sum2==0)
		 sum++;
	}
	if(flag==1)
	 cout<<ksm(2,sum-1)%mod<<endl;
	else
	 cout<<-1<<endl;
	return 0;
} 
