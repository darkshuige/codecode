#include<bits/stdc++.h>
using namespace std;
struct person
{
	int id;
	int a,b,c,sum;
};
int cmp(person a,person b)
{
	if(a.sum!=b.sum)
	 return a.sum>b.sum;
	else
	 if(a.a!=b.a)
	  return a.a>b.a;
	 else
	  return a.id<b.id;
}
int main()
{
	person a[305];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].sum=a[i].a+a[i].b+a[i].c;
		a[i].id=i;
	}	
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=5;i++)
	 cout<<a[i].id<<" "<<a[i].sum<<endl;
	return 0;
}
