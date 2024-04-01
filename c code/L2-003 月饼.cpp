#include<bits/stdc++.h>
using namespace std;
struct sb
{
	double price;
	double sl;
	double dj;
}a[100005];
double cmp(struct sb a,struct sb b)
{
	return a.dj>b.dj;
}
int main()
{
	int n,d;
	cin>>n>>d;
	int i;
	for(i=0;i<n;i++)
	 cin>>a[i].sl;
	for(i=0;i<n;i++)
	{
		cin>>a[i].price;
		a[i].dj=a[i].price/a[i].sl;
	}
	sort(a,a+n,cmp);
	double sum=0;
	i=0;
	while(d && i<n)
	{
		if(d-a[i].sl>0)
		{
			d-=a[i].sl;
			sum+=a[i].price;
		}
		else
		{
			sum+=a[i].dj*d;
			d=0;
		}
		i++;
	}
	printf("%.2f\n",sum);
	return 0;
}
