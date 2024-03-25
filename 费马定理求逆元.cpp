#include<iostream>
using namespace std;
typedef long long LL;
int a, p;
int quickpow(LL a, int b, int p)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = res*a%p;
		a = a*a%p;
		b >>= 1;
	}
	return res;
}
int main()
{
	cin >> a >> p;
	if(a % p)
	 printf("%d\n",quickpow(a,p-2,p));//a p互质，a^(p-2)就是a模p的乘法逆元
  return 0;
}