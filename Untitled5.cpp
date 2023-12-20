#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
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
	__int128 n,sum=0;
	scan(n);
	if(n<=4)
	{
		cout<<0<<endl;
		return 0;
	}
	if(n==5)
	{
		cout<<1<<endl;
		return 0;
	}
	if(n%2==0)
	{
		__int128 a=n-1;
		__int128 ji=a;
		__int128 op=ji%10;
		ji=ji/10;
		if(op>=5)
		{
			sum+=(ji)*(ji+1)/2*5;
		}
		else
		{
			sum+=(ji-1)*(ji)/2*5;
		}
		while(a%10!=5)
		{
			if(op>=5)
			 sum+=ji+1;
			else
			 sum+=ji;
			a-=2;
		}
		if(op>=5)
			 sum+=ji+1;
			else
			 sum+=ji;
		__int128 b=n/10;
		sum+=(b-1)*(b)/2*5;
		while(n%10!=0)
		{
			sum+=b;
			n-=2;
		}
		sum+=b;
	}
	else
	{
		__int128 a=n;
		__int128 ji=a;
		__int128 op=ji%10;
		ji=ji/10;
		if(op>=5)
		{
			sum+=(ji)*(ji+1)/2*5;
		}
		else
		{
			sum+=(ji-1)*(ji)/2*5;
		}
		while(a%10!=5)
		{
			if(op>=5)
			 sum+=ji+1;
			else
			 sum+=ji;
			a-=2;
		}
		if(op>=5)
			 sum+=ji+1;
			else
			 sum+=ji;
		n--;
		__int128 b=n/10;
		sum+=(b-1)*(b)/2*5;
		while(n%10!=0)
		{
			sum+=b;
			n-=2;
		}
		sum+=b;
	}
	print(sum);
	cout<<endl;
	return 0;
}
