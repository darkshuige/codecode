#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100010;
__int128 a[maxn],b[maxn],cnt[maxn];
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
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		memset(b,0,sizeof b);
		memset(cnt,0,sizeof cnt);
		int odd=0,even=0; 
		for(int i=1;i<=n;i++)
		{
			scan(a[i]);
			b[i]=b[i-1]+a[i];
			cnt[i]=cnt[i-1];
			 if(b[i]%2==1)
			  cnt[i]=++odd;
			 else
			  cnt[i]=++even;
		}
		while(q--)
		{
			int l,r,k;
			cin>>l>>r>>k;
			if(k-1>r-l)
			{ 
				cout<<"NO"<<endl;
				continue;
			}
			if(k==1)
			{
				if((b[r]-b[l-1])%2==0)
				 cout<<"YES"<<endl;
				else
				 cout<<"NO"<<endl;
				continue;
			}
			if(cnt[r]-cnt[l-1]>=k && b[l-1]%2==b[r]%2)
			 cout<<"YES"<<endl;
			else
			 cout<<"NO"<<endl;
		}
	}
	return 0;
}
