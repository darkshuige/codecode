#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=100005;
int f(int x,int op)
{
	int sum=0;
	while (x % op == 0)
    {
        sum ++ ;
        x /= op;
    }
	return sum;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int a2=0,a5=0;
	int c2=0,c5=0;
	for(int i=1;i<=n;i++)
	{
		int f1=4*i-2,f2=i+1;
		a2+=f(f1,2);
		a5+=f(f1,5);
		a2-=f(f2,2);
		a5-=f(f2,5);
		c2+=a2;
		c5+=a5;
	} 
	cout<<min(c2,c5)<<endl;
	return 0;
} 
