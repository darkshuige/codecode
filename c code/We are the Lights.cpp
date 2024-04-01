#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
int a[maxn],b[maxn],c[maxn];
signed main()
{
	jiasu;
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=q;i++)
	{
		int num;
		string op1,op2;
		cin>>op1>>num>>op2;
		c[i]=num;
		if(op1=="row")
		 a[i]=1;
		else
		 a[i]=2;
		if(op2=="on")
		 b[i]=1;
		else
		 b[i]=0;	
	} 
	int sum=0;
	map<int,int>hang,lie;
	for(int i=q;i>=1;i--)
	{
		if(a[i]==1)
		{
			if(!hang[c[i]])
			{
				hang[c[i]]++;
				n--;
				if(b[i]==1)
				 sum+=m;	
			}
		}
		else
		{
			if(!lie[c[i]])
			{
				lie[c[i]]++;
				m--;
				if(b[i]==1)
				 sum+=n;	
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}

