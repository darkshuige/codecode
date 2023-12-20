#include<bits/stdc++.h>
using namespace std;
const int maxn=4000005;
struct node
{
	int l,r;
	char date;
}g[maxn]; 
void pre(int root)
{
	cout<<g[root].date;
	if(g[root].l!=-1)
	{
		if(g[g[root].l].date!='#')
		 pre(g[root].l);
	}
	if(g[root].r!=-1)
	{
		if(g[g[root].r].date!='#')
		 pre(g[root].r);
	}
}
void in(int root)
{
	if(g[root].l!=-1)
	{
		if(g[g[root].l].date!='#')
		 in(g[root].l);
	}
	cout<<g[root].date;
	if(g[root].r!=-1)
	{
		if(g[g[root].r].date!='#')
		 in(g[root].r);
	}
}
void post(int root)
{
	if(g[root].l!=-1)
	{
		if(g[g[root].l].date!='#')
		 post(g[root].l);
	}
	if(g[root].r!=-1)
	{
		if(g[g[root].r].date!='#')
		 post(g[root].r);
	}
	cout<<g[root].date;
}
int main()
{
    string s="0";
    string a;
    cin>>a;
    s+=a;
    int n=s.size();
    for(int i=1;i<n;i++)
    {
		g[i].l=g[i].r=-1;
		g[i].date=s[i];
		if(i*2<n)
		 g[i].l=i*2;
		if(i*2+1<n)
		 g[i].r=i*2+1;    	
	}
	if(s[1]!='#')
	{
		pre(1); cout<<endl;
		in(1);  cout<<endl;
		post(1); cout<<endl;
	}
	int sum=0;
	for(int i=1;i<n;i++)
	{
		if(g[i].l!=-1)
		 if(g[g[i].l].date=='#')
		  g[i].l=-1;
		if(g[i].r!=-1)
		 if(g[g[i].r].date=='#')
		  g[i].r=-1;
	}
	for(int i=2;i<n;i++)
	 if(g[i].l==g[i].r && g[i].date!='#')
	  sum++;
	cout<<sum<<endl;
    return 0;
}
//abcd
//0abcd
//01234
