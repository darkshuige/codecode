#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(flase),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
signed main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int k,n;
		cin>>n>>k;
		string s;
		cin>>s;
		int pos=0;
		int flag=0;
		int p=s.find("0");
		if(p==string::npos && k==1)
		{
			s[n-1]='0';
			cout<<s<<endl;
			continue;
		}
		if(n==1)
		{
			if(k%2==0)
			{
			}
			else
			{
				s[0]='0';		
			}	
		} 
		else
		{
			while(pos<n && k>0)
			{
				if(s[pos]=='0' && flag==0)
				{
					s[pos]='1';
					flag=1;
				}
				else if(s[pos]=='0' && flag==1)
				{
					s[pos]='1';
				}
				else if(s[pos]=='1' && flag==1)
				{
					flag=0;
					k--;
				}
				pos++;
			}	
		}
		
		cout<<s<<endl;
	}
	return 0;
}
 
