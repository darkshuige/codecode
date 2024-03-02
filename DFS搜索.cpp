#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cou.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int flag1=0,flag2=0,flag3=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='D')
			 flag1=1;
			if(s[i]=='F' && flag1==1)
			 flag2=1;
			if(s[i]=='S' && flag1==1 && flag2==1)
			 flag3=1;
		}
		if(flag1==1 && flag2==1 && flag3==1)
		 cout<<1<<" ";
		else
		 cout<<0<<" ";
		flag1=0,flag2=0,flag3=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='d')
			 flag1=1;
			if(s[i]=='f' && flag1==1)
			 flag2=1;
			if(s[i]=='s' && flag1==1 && flag2==1)
			 flag3=1;
		}
		if(flag1==1 && flag2==1 && flag3==1)
		 cout<<1<<endl;
		else
		 cout<<0<<endl;
	}
    return 0;
}