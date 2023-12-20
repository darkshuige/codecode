#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=3050;
signed main()
{
	jiasu;
	int a[10];
	for(int i=0;i<8;i++)
	 a[i]=i+1;
	do
	{
		for(int i=0;i<8;i++)
		{
			if(i!=0)
			 cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}while(next_permutation(a,a+8));
	return 0;
} 
