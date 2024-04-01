#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;
double PI=acos(-1);
signed main()
{
	string s;
	cin>>s;
	int a=0,b=0;
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a')
		 a++;
		else
		 b++;
		if(a==0)
		 sum+=2;
		else if(a<10)
		 sum+=1;
		else if(a%10==0)
		 sum+=1;
		if(b==0)
		 sum+=2;
		else if(b<10)
		 sum+=1;
		else if(b%10==0)
		 sum+=1;
	}
	cout<<sum<<endl;
	return 0;
}
