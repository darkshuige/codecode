#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
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
//	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		__int128 ans;
		if(n>=1000000000)
		{
			ans=(n-999999999)*10+1*9+2*90+3*900+(__int128)4*9000+(__int128)5*90000+(__int128)6*900000+(__int128)7*9000000+(__int128)8*90000000+(__int128)9*900000000;
		}
		else if(n>=100000000)
		{
			ans=(n-99999999)*9+1*9+2*90+3*900+4*9000+5*90000+(__int128)6*900000+(__int128)7*9000000+(__int128)8*90000000  ;
		}
		else if(n>=10000000)
		{
			ans=(n-9999999)*8+1*9+2*90+3*900+4*9000+5*90000+(__int128)6*900000+(__int128)7*9000000  ;
		}
		else if(n>=1000000)
		{
			ans=(n-999999)*7+1*9+2*90+3*900+4*9000+(__int128)5*90000+(__int128)6*900000  ;
		}
		else if(n>=100000)
		{
			ans=(n-99999)*6+1*9+2*90+3*900+4*9000+(__int128)5*90000  ;
		}
		else if(n>=10000)
		{
			ans=(n-9999)*5+1*9+2*90+3*900+4*9000  ;
		}
		else if(n>=1000)
		{
			ans=(n-999)*4+1*9+2*90+3*900  ;
		}
		else if(n>=100)
		{
			ans=(n-99)*3+1*9+2*90  ;
		}
		else if(n>=10)
		{
			ans=(n-9)*2+1*9  ;
		}
		else
		{
			ans=n  ; 
		}
		print(ans);
		cout<<endl;
	} 
	return 0;
}
