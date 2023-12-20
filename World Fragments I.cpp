#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
__int128 ksm(int a,int b)
{
	__int128 ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a);
		a=(a*a);
		b>>=1;
	}
	return ans;
}
void print(__int128 num)
{
	if(num>9) 
	 print(num/10);
	putchar(num%10+'0');
}
signed main()
{
//	jiasu;
	string a,b;
	cin>>a>>b;
	if(a[0]=='0' && a!=b)
	{
		cout<<-1<<endl;
		return 0;	
	}	
	__int128 sum=0,a1=0,b1=0;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=0;i<a.size();i++)
	 a1+=ksm(2,i)*(a[i]-'0');
	for(int i=0;i<b.size();i++)
	 b1+=ksm(2,i)*(b[i]-'0');
	sum=max(a1,b1)-min(a1,b1);
	print(sum);
//	cout<<endl;
	return 0;
}
