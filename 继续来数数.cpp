#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int mod=1000000007;
const int maxn=1000005;
int a[maxn];
bool flag[maxn]={0};

const int maxn1=1000000; 
bool arr[maxn1+1]={false}; 
vector<int>produce_prim_number() 
{ 
    vector<int> prim; 
    prim.push_back(2); 
    int i,j; 
    for(i=3;i*i<=maxn1;i+=2) 
    { 
        if(!arr[i]) 
        { 
            prim.push_back(i); 
            for(j=i*i;j<=maxn1;j+=i) 
                arr[j]=true; 
        } 
    } 
    while(i<maxn1) 
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
int com(int n,int m) 
{ 
    const int M=mod; 
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
		memset(flag,0,sizeof flag);
		memset(a,0,sizeof a);
		int f=0;
		int pos1=-1;
		int pos2=-1;
		int n,k;
		cin>>n>>k;
		if(n==k)
		{
			cout<<1<<endl;
			for(int i=1;i<=n;i++)
			 cin>>a[i];
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(flag[a[i]]==0)
			 flag[a[i]]=1;
			else
			{
				f=1;
				pos2=i;
				for(int j=1;j<i;j++)
				 if(a[j]==a[i])
				  pos1=j;
			}
		}
		if(k==1)
		{
			int ans=com(n,n-k);
			cout<<ans-1<<endl;
		}
		else if(n==1)
		{
			cout<<1<<endl;
		}
		else
		{
			if(f==1)
			{
				int ans=com(n,n-k),jian=0;
				if(abs(pos1-pos2)==1)
				 jian=com(n-2,k-1);
				else if(abs(pos1-pos2)==2)
				 jian=com(n-k,n-2);
				ans=(ans-jian+mod)%mod;
				cout<<ans<<endl;
			}
			else if(f==0) 
			{
				cout<<com(n,n-k)<<endl;
			}	
		}
		
	}
	return 0;
}

