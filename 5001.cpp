#include<iostream>
using namespace std;
const long long mod = 1e9+7;
long long a[100005]={0};
void init()
{
	a[0]=1;
	a[1]=1;
	a[2]=3;
	for(int i=3;i<=100000;i++)
	 a[i]=((i*a[i-1])%mod+((i-1)*a[i-2])%mod)%mod;
}
int main()
{
    init();
    int n;
    cin>>n;
	cout<<a[n];
    return 0;
}
