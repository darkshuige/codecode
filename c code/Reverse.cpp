#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=1000005;
int b[maxn]={0};
char a[maxn];
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int k=0;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]=='1')
		 cnt++;
		else
		{
			b[k++]=cnt;
			cnt=0;
		}
	}
	b[k++]=cnt;
	sort(b,b+k,cmp);
	cout<<b[0]+b[1]<<endl;
	return 0;
} 
