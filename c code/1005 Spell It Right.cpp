#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
signed main()
{
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		sum+=(s[i]-'0');
	}
	string ans=to_string(sum);
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) cout<<" ";
		if(ans[i]=='0')
		 cout<<"zero";
		else if(ans[i]=='1')
		 cout<<"one";
		else if(ans[i]=='2')
		 cout<<"two";
		else if(ans[i]=='3')
		 cout<<"three";
		else if(ans[i]=='4')
		 cout<<"four";
		else if(ans[i]=='5')
		 cout<<"five";
		else if(ans[i]=='6')
		 cout<<"six";
		else if(ans[i]=='7')
		 cout<<"seven";
		else if(ans[i]=='8')
		 cout<<"eight";
		else if(ans[i]=='9')
		 cout<<"nine";
	}
	return 0;
} 