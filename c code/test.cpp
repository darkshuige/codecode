#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
int ans[1001],lena;
void add(int b[],int len)//加
{
	lena=max(len,lena);
	for(int i=1;i<=lena;i++)
	{
		ans[i]+=b[i];
		ans[i+1]+=ans[i]/10;	
		ans[i]%=10;
	}
	if(ans[lena+1])++lena;
}
int b[1001];
void pow(ll x)//求底数为二的幂
{
	memset(b,0,sizeof(b));
	int k=1;
	b[1]=1;
	for(int i=1;i<=x;++i)
    {
        int md=0;//保存进位
        for(int j=1;j<=k;++j)
        {
            b[j]=b[j]*2+md;
            md=b[j]/10;
            b[j]%=10;
            if(md&&j==k)++k;
        }
    }
	add(b,k);
}
ll Qpow(ll a,ll x)//快速幂
{
	ll res=1;
	while(x)
	{
		if(x&1)res*=a;
		a*=a;
		x>>=1;
	}
	return res;
}
int p;	
string s;
ll check(ll x,ll h)//h为左括号数量，返回值应为2()这个幂的大小，并添加进ans
{
    ll q=0;//q为指数
	p=0;
    for(int i=x;i<s.length();i++)
    {
        p=max(p,i);
        if(s[i]=='(') h++;
        if(s[i]==')') h--;
        if(!h)//左右括号对应时退出循环，并将幂的结果加入ans
		{
			pow(q);
			return 0;
		}
		//不是最后一个右括号
        if(s[i]==')') return Qpow(2,q);//不对应时计算幂
        if(s[i]=='2')
        {
            if(s[i+1]=='(') q+=check(i+1,h),i=p;
            else q+=2;
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='2')
		{
			if(s[i+1]=='(')
			{
				check(i+1,0);
				i=p;//指针i跳转至对应的右括号
			}
			else //此时s[i]只是个单纯的2，不是2的幂
			{
				memset(b,0,sizeof(b));
				b[1]=2;
				add(b,1);
			}
		}
	}
	for(int i=lena;i>=1;i--)
	{
		cout<<ans[i];
	}
}
