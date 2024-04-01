#include<bits/stdc++.h>
using namespace std;
int n;
struct ww
{
	int a;
	int b;
}s[100001];
bool cmp(ww x,ww y)
{
	return x.a>y.a;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].a;
	}
	for(int i=0;i<n;i++)
	{
		cin>>s[i].b;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i].a<s[i].b)
		{
			swap(s[i].a,s[i].b);
		}
	}
	sort(s,s+n,cmp);
	int as=1e9;
	int mx=s[0].b,mi=s[n-1].a;
	for(int i=0;i<n;i++)
	{
		as=min(as,max(mx,s[i].a)-mi);
        if(mx<s[i].a)
		{
			mx=max(mx,s[i].b);
        }
        if(mi>s[i].b)
		{
			mi=min(mi,s[i].b);
        }
	}
	cout<<as;
} 
