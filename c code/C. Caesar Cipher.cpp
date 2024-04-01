#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200;
const int mod=1000000007;
map<char,int>mp;
char num[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
void init()
{
	for(int i=0;i<26;i++)
	 mp['A'+i]=i;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	int cnt=1;
	init();
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		int c=s2[0]-s1[0];
		cout<<"Case #"<<cnt<<": ";
		for(int i=0;i<m;i++)
		{
			if(c>=0)
			 cout<<num[(mp[s3[i]]+26-c)%26];
			else
			 cout<<num[(mp[s3[i]]-c)%26];
		}
		cnt++;
		cout<<endl;
	}
	return 0;
}

//3
//1 26
//B
//A
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//1 26
//A
//B
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//1 26
//A
//A
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

