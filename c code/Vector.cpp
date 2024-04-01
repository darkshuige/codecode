#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
int a[4],b[4],c[4];
int gcd(int aa,int bb)
{
	if(aa==0)
	 return bb;
	if(bb==0)
	 return aa;
	if(aa<bb)
	 swap(aa,bb);
	int t=aa%bb;
	while(t)
	{
		aa=bb;
		bb=t;
		t=aa%bb;
	}
	return bb;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<4;i++)
		 cin>>a[i]>>b[i]>>c[i];
		if((a[0]==0 && a[1]==0 && a[2]==0 && a[3]!=0) || (b[0]==0 && b[1]==0 && b[2]==0 && b[3]!=0) || (c[0]==0 && c[1]==0 && c[2]==0 && c[3]!=0))
		{
			cout<<"NO"<<endl;
			continue;
		}
		int g1=gcd(a[0],a[1]),g2=gcd(b[0],b[1]),g3=gcd(c[0],c[1]);
		g1=gcd(g1,a[2]),g2=gcd(g2,b[2]),g3=gcd(g3,c[2]);
		if(a[3]%g1==0 && b[3]%g2==0 && c[3]%g3==0)
		 cout<<"YES"<<endl;
		else 
		 cout<<"NO"<<endl;
	}
	return 0;
}
