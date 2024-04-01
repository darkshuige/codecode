#include<bits/stdc++.h>
using namespace std;
struct cj
{
	int s,e,y;
	double ave;
}a[5005];
int cmp(struct cj a,struct cj b)
{
	if(a.ave!=b.ave)
	 return a.ave>b.ave;
	else
	 if(a.s!=b.s)
	  return a.s>b.s;
	 else
	  if(a.y!=b.y)
	   return a.y>b.y;
	  else
	   if(a.e!=b.e)
	    return a.e>b.e;
}
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i].s>>a[i].e>>a[i].y;
			a[i].ave=(double)(a[i].s+a[i].y+a[i].e)/3.0;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			cout<<a[i].s<<" "<<a[i].y<<" "<<a[i].e<<" ";
			printf("%.2f\n",a[i].ave);	
		}	
	}
	
	return 0;
}
