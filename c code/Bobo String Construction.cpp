#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
string a,b;
int kmp_next[1000010];
void getNext(int m)
{
    int j = 0;
    kmp_next[0] = 0;
    for(int i=1; i<m; ++i)
	{
        while(j>0 && b[i]!=b[j])
		 j=kmp_next[j-1];
        if(b[i]==b[j]) 
		 ++j;
        kmp_next[i] = j;
    }
}
int kmp(int n,int m)
{
    int i, j = 0, res = 0;
    getNext(m);
    for(i=0; i<n; ++i)
	{
        while(j>0 && b[j]!=a[i])
		 j=kmp_next[j-1];
        if(b[j]==a[i]) 
		 ++j;
        if(j==m)
		 ++res;
    }
    return res;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cin>>b;
		string ans="";
		for(int i=0;i<n;i++)
		 ans+="0";
		a=b+ans+b;
		if(kmp(a.size(),b.size())>=3)
		{
			for(int i=0;i<n;i++)
			 cout<<"1";
			cout<<endl;	
		}
		else
		 cout<<ans<<endl;
	}
	return 0;
}
