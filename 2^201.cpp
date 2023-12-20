#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
const int m=1<<20;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int num;
		int cha=INT_MAX;
		int n;
		cin>>n;
		for(int i=(1<<20);i<=(1<<30);i<<=1)
		{
			if(i-n>=0 && i-n<cha)
			{
				cha=i-n;
				num=i;
				break;
			}
		}
		int pos=1;
		while(pos<n)
		 pos<<=1;
		int sum=0;
		while(n<pos)
		{
			if((n<<1)<=pos && n!=0)
			{
				n<<=1;
				sum++;
			}
			else
			{
				n+=1;
				sum++;
			}
		}
		while(n<num)
		{
			n<<=1;
			sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
