	#include<bits/stdc++.h>
	#define int long long
	//#define endl "\n"
	#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
	using namespace std;
	const int maxn=1000005;
	char a[maxn];
	signed main()
	{
		jiasu;
	    int n,q;
	    cin>>n>>q;
	    a[0]='#';
	    a[n+1]=='#';
	    int ss=0;
	    for(int i=1;i<=n;i++)
	    {
	    	cin>>a[i];
	    	if(a[i-1]=='1' && a[i]=='0')
			 ss++;
		}
		if(a[n]=='1') ss++;
		while(q--)
		{
			int sum=ss;
			int l,r;
			cin>>l>>r;
			if(r==l+1)
			{
				if(a[l]==a[r])
				 sum=sum;
				else
				{
					if(l>1 && r<n)
					{
						if(a[l-1]==a[r+1]) sum=sum;
						else
						{
							if(a[l]==a[l-1]) sum++;
							else sum--;
						}
					}
					else if(l==1 && r==n) sum=sum;
					else if(l==1)
					{
						if(a[l]=='0' && a[r]=='1')
						{
							if(a[r+1]=='1') sum++;
						}
						else if(a[l]=='1' && a[r]=='0')
						{
							if(a[r+1]=='1') sum--;
						}
					}
					else if(r==n)
					{
						if(a[r]=='0' && a[l]=='1')
						{
							if(a[l-1]=='1') sum++;
						}
						else if(a[r]=='1' && a[l]=='0')
						{
							if(a[l-1]=='1') sum--;
						}
					}
				}
			}
			else if(l>1 && l<n && r>1 && r<n)
			{
				if(a[l]==a[r])
				 sum=sum;
				else
				{
					if(a[l-1]==a[r+1])
					 sum=sum;
					else
					{
						if(a[l]==a[l-1] && a[r]==a[r+1])
						 sum++;
						else
						 sum--;	
					}
				}
			}
			else if(l==1 && r==n)
			{
				sum=sum;
			}
			cout<<sum<<endl;
		}
	    return 0;
	}
	
