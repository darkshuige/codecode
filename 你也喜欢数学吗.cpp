#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
//#define int long long
using namespace std;
const int mod=1000000007;
int main()
{
	jiasu;
	long long k;
	cin>>k;
	long long sum=(__int128(k+2)*__int128(k+1)*__int128(k)/6)%mod;
	cout<<sum<<endl;
	return 0;
} 
