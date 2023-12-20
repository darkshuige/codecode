#include<iostream>
#include<cstdio>     //EOF,NULL
#include<cstring>    //memset
#include<cstdlib>    //rand,srand,system,itoa(int),atoi(char[]),atof(),malloc
#include<cmath>           //ceil,floor,exp,log(e),log10(10),hypot(sqrt(x^2+y^2)),cbrt(sqrt(x^2+y^2+z^2))
#include<algorithm>  //fill,reverse,next_permutation,__gcd,
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<iterator>
#include<iomanip>             //setw(set_min_width),setfill(char),setprecision(n),fixed,
#include<functional>
#include<map>
#include<set>
#include<limits.h>     //INT_MAX
#include<bitset> // bitset<?> n
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
const int maxn=1000005;
typedef long long ll;
typedef unsigned long long ull;
const ll mod=1e9+7;
const double pi=acos(-1.0); 
const int INF =0x3f3f3f3f;
const int inf = 0x3f3f3f3f;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a);
		a=(a*a);
		b>>=1;
	}
	return ans;
}
signed main()
{
	jiasu;
	int t,k,n;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k;
		cin>>n>>k;
		cout<<"Case #"<<i<<": ";
		int pos=2;
		int sum=ksm(2,k)-1;
		while(ksm(pos+1,k)<=n)
		{
			for(int j=ksm(pos,k);j<=ksm(pos+1,k)-1;j++)
			{
				if(j%pos==0)
				{
					sum++;
					j+=(pos-1);
				}
			}
			pos++;
		}
		for(int j=ksm(pos,k);j<=n;j++)
		 if(j%pos==0)
		  sum++,j+=(pos-1);
		cout<<sum<<endl;
	}
}
