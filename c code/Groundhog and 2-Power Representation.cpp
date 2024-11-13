#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=185;
string s;
int a[N*2],ans[N*2],t[N*2],b[N*2];
void add()
{
	for(int i=0;i<N;i++)
	{
		ans[i]+=b[i];
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
}
void mul(int*a, int*b, int*c)
{
	memset(t,0,sizeof(t));
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			t[i+j] += a[i]*b[j];
			t[i+j+1] += t[i+j]/10;
			t[i+j] %= 10;    
		}
	}
	memcpy(c,t,sizeof(t));
}
void ksm(int n)
{
	memset(a,0,sizeof a); memset(b,0,sizeof b);
	b[0]=1, a[0]=2;
	while(n)
	{
		if(n & 1) mul(b,a,b);
		mul(a,a,a);
		n >>= 1;
	}
}
int qpow(int a,int x)//快速幂
{
	int res=1;
	while(x)
	{
		if(x&1)res*=a;
		a*=a;
		x>>=1;
	}
	return res;
}
int p;
int f(int x,int h)
{
    int q=0;
	p=0;
    for(int i=x;i<(int)s.size();i++)
    {
        p=max(p,i);
        if(s[i]=='(') h++;
        if(s[i]==')') h--;
        if(h==0)
		{
			ksm(q);
			add();
			return 0;
		}
        if(s[i]==')') return qpow(2,q);
        if(s[i]=='2')
        {
            if(s[i+1]=='(') q+=f(i+1,h),i=p;
            else q+=2;
        }
    }
    return 0;
}
signed main()
{
	jiasu;
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]=='2')
		{
			if(s[i+1]=='(')
			{
				f(i+1,0);
				i=p;
			}
			else
			{
				memset(b,0,sizeof b);
				b[0]=2;
				add();
			}
		}
	}
	int pos=N-1;
	while(ans[pos]==0)
	 pos--;
	for(int i=pos;i>=0;i--)
	 cout<<ans[i];
	return 0;
}