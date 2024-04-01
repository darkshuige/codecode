#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
struct node
{
	int p;
	double q;
}a[maxn],b[maxn],c[maxn*2];
signed main()
{
	int k1;
	while(cin>>k1)
	{
		for(int i=0;i<k1;i++)
		 cin>>a[i].p>>a[i].q;
		int k2;
		cin>>k2;
		for(int i=0;i<k2;i++)
		 cin>>b[i].p>>b[i].q;
		int pos=0,p1=0,p2=0;
		while(p1<k1 && p2<k2)
		{
			if(a[p1].p>b[p2].p)
			 c[pos++]=a[p1++];
			else if(a[p1].p<b[p2].p)
			 c[pos++]=b[p2++];
			else
			{
				if(a[p1].q+b[p2].q!=0)
				{
					c[pos]=a[p1++];
					c[pos++].q+=b[p2++].q;	
				}
				else
				{
					p1++;
					p2++;
				}
			}
		}
		while(p1<k1)
		 c[pos++]=a[p1++];
		while(p2<k2)
		 c[pos++]=b[p2++];
		while(c[pos-1].q==0 && pos)
		 pos--;
		cout<<pos;
		for(int i=0;i<pos;i++)
		{
			cout<<" ";
			cout<<c[i].p<<" "<<fixed<<setprecision(1)<<c[i].q;
		}
		cout<<endl;
	}
	return 0;
} 
