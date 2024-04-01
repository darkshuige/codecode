const int maxn=1000;
int fac[maxn+100],ifac[maxn+100];
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
void init(void)
{
	fac[0]=1;
	for(int i=1;i<=maxn;i++) fac[i]=fac[i-1]*i%mod;
	ifac[maxn]=ksm(fac[maxn],mod-2);
	for(int i=maxn;i>=1;i--) ifac[i-1]=ifac[i]*i%mod;
}

int C(int a,int b)
{
	if(a<b || b<0) return 0;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
