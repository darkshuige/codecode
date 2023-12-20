#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
const int maxn=1000000+1;
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
bool arr[maxn]={false}; 
vector<int> produce_prim_number() 
{ 
        vector<int> prim; 
        prim.push_back(2); 
        int i,j; 
        for(i=3;i*i<=maxn;i+=2) 
        { 
                if(!arr[i]) 
                { 
                        prim.push_back(i); 
                        for(j=i*i;j<=maxn;j+=i) 
                                arr[j]=true; 
                } 
        } 
        while(i<maxn) 
        { 
                if(!arr[i]) 
                        prim.push_back(i); 
                i+=2; 
        } 
        return prim; 
} 
int cal(int x,int p) 
{ 
        int ans=0; 
        long long rec=p; 
        while(x>=rec) 
        { 
                ans+=x/rec; 
                rec*=p; 
        } 
        return ans; 
} 
int pow(long long n,int k,int M) 
{ 
        long long ans=1; 
        while(k) 
        { 
                if(k&1) 
                { 
                        ans=(ans*n)%M; 
                } 
                n=(n*n)%M; 
                k>>=1; 
        } 
        return ans; 
} 
int combination(int n,int m) 
{ 
        const int M=10007; 
        vector<int> prim=produce_prim_number(); 
        long long ans=1; 
        int num; 
        for(int i=0;i<prim.size()&&prim[i]<=n;++i) 
        { 
                num=cal(n,prim[i])-cal(m,prim[i])-cal(n-m,prim[i]); 
                ans=(ans*pow(prim[i],num,M))%M; 
        } 
        return ans; 
} 
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		int fz=0,fm=0;
		fm=ksm(b,n);
		for(int i=1;i<=n;i++)
		{
			int c=combination(n,i);
			int sum=0;
			for(int j=1;j<=i;j++)
			 sum=(sum+ksm(j,m))%mod;
			c=(c*sum)%mod;
			fz=(fz+c)%mod;
		}
		int ny=ksm(fm,mod-2); 
		cout<<fz*ny%mod<<endl;
	}
	return 0;
}
