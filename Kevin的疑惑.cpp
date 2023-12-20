#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200005;
int a[maxn];
void scan(__int128 &x)
{
	x=0;int f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
inline void print(__int128 x)
{
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
signed main()
{
	//jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		__int128 n,m,k;
		scan(n);scan(m);scan(k);
		if(k==1)
		{
			print(m);cout<<endl;
		}
		else if(n+m*2<k)
		{
			print(m+n);cout<<endl;
		}
		else if(k%2==0)
		{
			__int128 sum=(n+m*2)%k;
			__int128 ans=0;
			ans+=min(sum/2,m);
			sum-=2*ans;
			ans+=sum;
			print(ans);cout<<endl;
		}
		else if(k%2==1)
		{
			__int128 ans=0;
			__int128 
			
			print(ans);cout<<endl;
		}
	}
	return 0;
} 
