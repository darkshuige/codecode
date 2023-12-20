#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1e6+10;
const int mod=1e9+7;
char word[]={'_','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','.'};
map<char,int>mp;
int a[maxn];
signed main()
{
	for(int i=0;i<28;i++)
	 mp[word[i]]=i;
	int n;
	string s;
	while(cin>>n)
	{
		if(n==0) break;
		cin>>s;
		int k=n;
		int l=s.size();
		for(int i=0;i<l;i++)
		{
			a[k*i%l]=(mp[s[i]]+i)%28;
		}
		for(int i=0;i<l;i++)
		 cout<<word[a[i]];
		cout<<endl;
	}
	return 0;
} 
