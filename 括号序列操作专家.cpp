#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		string s;
		cin>>n>>s;
		int sum1=0,sum2=0;
		for(int i=0;i<n;i++)
		 if(s[i]=='(')
		  sum1++;
		 else
		  sum2++;
		if(sum1!=sum2)
		{
			cout<<-1<<endl;
			continue;
		}
		int ans=0,l=0,r=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==')')
			{
				if(l)
				 l--;
				else
				 r++;
			}
			else
			{
				if(r)
				{
					ans+=r;
					r--;
				}
				else
				 l++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
