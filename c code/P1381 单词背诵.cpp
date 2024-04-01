#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
map<string,int>mp1,cnt;
string a[100005];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		mp1[s]=1;
	}
	int i=0,j=0,len=INT_MAX,sum=0;
	int m;
	cin>>m;
	for(int k=0;k<m;k++)
	 cin>>a[k];
	while(j<m)
	{
		if(mp1[a[j]])
		{
			cnt[a[j]]++;
			if(cnt[a[j]]==1)
			{
				len=j-i+1;
				sum++;	
			}
		}
		while(i<=j)
		{
			if(cnt[a[i]]==1)
			 break;
			if(cnt[a[i]]>=2)
			{
				cnt[a[i]]--;
				i++;
			}
			if(!mp1[a[i]])
			 i++;
			len=min(len,j-i+1);
		}
		j++;
	}
	cout<<sum<<endl<<len<<endl;
	return 0;
}
