#include<bits/stdc++.h>
<<<<<<< HEAD
#define int long long
#define endl "\n"
using namespace std;
int isf(int k)
{
	if(k==0 || k==1) return 0;
	for(int i=2;i<k;i++)
	 if(k%i==0)
	  return 0;
	return 1;
}
int sanif(int k)
{
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	return 1;
}
int erif(int k)
{
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	return 1;
}
int wuif(int k)
{
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	return 1;
}
int siif(int k)
{
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	k/=10;
	if(isf(k%10)==0)
	 return 0;
	return 1;
}
signed main()
{
	for(int i=100;i<=999;i++)
	{
		for(int j=10;j<=99;j++)
		{
			if(sanif(i) && erif(j) && wuif(i*j) && siif(i*(j%10)) && siif(i*(j/10%10)))
			{
				cout<<i<<" "<<j<<endl;
				cout<<i*j<<endl;
			}
		}
	}
	return 0;
}
=======
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
int f(int n, int x) 
{
    int result = 0;
    for (int i = 0; i < n; ++i) 
	{
        if (x & ((int)1 << i))
		{
            result +=((int)(1) << (n - i - 1));
        }
    }
    return result;
}
signed main() 
{
    jiasu;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) 
	{
        int x;
        cin >> x;
        cout<<f(n,x)<<endl;
    }
    return 0;
}
>>>>>>> 18367802e2510931f1925364fd3d3e7047de7c38
