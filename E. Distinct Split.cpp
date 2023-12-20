#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int f1[30]={0},f2[30]={0};
		string s;
		cin>>s;
		for(int j=0;j<n;j++)
		{
			f1[s[j]-'a']++;
		}
		int maxn=0;
		for(int j=0;j<26;j++)
		 if(f1[j]!=0)
		  maxn++;
		for(int j=0;j<n;j++)
		{
			f1[s[j]-'a']--;
			f2[s[j]-'a']++;
			int sum=0;
			for(int j=0;j<26;j++)
			{
				if(f1[j]!=0)
				 sum++;
				if(f2[j]!=0)
				 sum++;
			}
			maxn=max(maxn,sum);
		}
		cout<<maxn<<endl;
	}
    return 0;
}
