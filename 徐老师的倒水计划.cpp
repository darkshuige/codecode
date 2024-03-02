#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int d[100005];
int main()
{
	long long pos1,pos2,i;
	long long sum=0;
	pos1=0;
	pos2=0;
	i=1;
	while(sum<=5000000000)
	{
		sum+=i;
		if(sum%2==1)
		{
			pos1++;
			a[pos1]=sum;
			c[pos1]=i;
		}
		if(sum%2==0)
		{
			pos2++;
			b[pos2]=sum;
			d[pos2]=i;
		}
		i++;
	}
	int t;
	cin >> t;
	while(t--)
	{
		int q,p;
		cin >> q >> p;
		int x=max(q,p)-min(q,p);
		if(x==0)
		{
			cout << 0 << endl;
			continue;
		}
		int pos;
		if(x%2==1)
		{
			pos=lower_bound(a+1,a+pos1,x)-a;
			cout << c[pos] << endl;
		}
		if(x%2==0)
		{
			pos=lower_bound(b+1,b+pos2,x)-b;
			cout << d[pos] << endl;
		}
	}
}