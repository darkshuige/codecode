#include<bits/stdc++.h>
using namespace std;
long long gys(long long a,long long b)
{
	a=abs(a),b=abs(b);
	long long t;
	if(a<b)
	{
		t=a;a=b;b=t;
	}
	t=a%b;
	while(t)
	{
		a=b;
		b=t;
		t=a%b;
	}
	return b;
}
void add(pair<long long,long long>&a,pair<long long,long long>&b)
{
	long long fm;
	long long fz;
	fm=a.second*b.second;
	fz=a.first*b.second+b.first*a.second;
	if(fz==0)
	{
		b.first=0;b.second=0;return;
	}
	long long g=gys(fz,fm);
	b.first=fz/g;
	b.second=fm/g;
}
int main()
{
	long long n;
	char k;
	pair<long long,long long>p[100];
	cin>>n;
	long long i;
	for(i=0;i<n;i++)
	 cin>>p[i].first>>k>>p[i].second;
	for(i=1;i<n;i++)
	{
		add(p[i-1],p[i]);
	}
	if(p[i-1].first==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	long long g=gys(p[i-1].first,p[i-1].second);
	p[i-1].first=p[i-1].first/g;
	p[i-1].second=p[i-1].second/g;
	if(p[n-1].first%p[n-1].second==0)
	 cout<<p[n-1].first/p[n-1].second<<endl;
	else
	{
		if(abs(p[n-1].second)>abs(p[n-1].first))
		 printf("%d/%d\n",p[n-1].first,p[n-1].second);	
		else
		{
			cout<<p[n-1].first/p[n-1].second<<" ";
			if(p[n-1].first<0)
			{
				p[n-1].first+=p[n-1].second*(abs(p[n-1].first/p[n-1].second));
			}
			else
			{
				p[n-1].first-=p[n-1].second*(p[n-1].first/p[n-1].second);
			}
			printf("%d/%d\n",p[n-1].first,p[n-1].second);
		}
	}
	return 0;
}
