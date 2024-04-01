#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cou.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int sum=0;
	for(int i=2023;i<=20231122;i++)
	{
		string s=to_string(i);
		for(int j=0;j<=s.size()-4;j++)
		{
			if(s[j]=='1' && s[j+1]=='1' && s[j+2]=='2' && s[j+3]=='2')
			{
				cout<<s<<endl;
				sum++;
			}
			 
		}
	}
	cout<<sum<<endl;
	return 0;
}